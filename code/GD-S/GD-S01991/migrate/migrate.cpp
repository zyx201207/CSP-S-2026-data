#include<bits/stdc++.h>
//±©Á¦24~40·Ö 
#define int long long
using namespace std;
const int N=2e6+10,inf=2e18+10;
int op,t,n,d,x[N],dp[N],p[N],ans,s[N];
int bs(int l,int r,int x){
	while(l<r){
		int mid=(l+r+1)/2;
		if(dp[mid]<=x) l=mid;
		else r=mid-1;
	}
	return l;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>op>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[j]=inf;
				p[j]=0;
			}
			for(int j=1;j<=n;j++) s[j]=0;
			dp[i]=0;
			p[i]=1;
			s[i]=1;
			for(int j=i+1;j<=n;j++){
				int pos=lower_bound(x+i,x+1+j-1,x[j]-d)-x;
				pos=max(pos,i);
				int q=bs(pos,j-1,dp[pos]);
				//cout<<i<<" "<<j<<" "<<q<<endl;
				dp[j]=min(dp[j],dp[pos]+1);
				p[j]=s[q]-s[pos-1];
				s[j]=s[j-1]+p[j];
			}
			//for(int j=i+1;j<=n;j++) cout<<j<<" "<<p[j]<<endl;
			for(int j=i+1;j<=n;j++){
				if(p[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

