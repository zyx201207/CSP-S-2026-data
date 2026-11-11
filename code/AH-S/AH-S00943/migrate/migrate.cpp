#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,T,n;
ll d,x[2000005],dp[2000005],l,r,ans,dd,ddd,mm[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)
				cin>>x[i];
			dd=d/(x[2]-x[1]);
			if(dd>=2)
				ans=max((ll)0,n-2*dd+1);
			else
				ans=0;
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(c==13||c==14){
		while(T--){
			ans=0;
			cin>>n>>d;
			l=r=-1;
			for(int i=1;i<=n;i++)
				cin>>x[i];
			for(int i=1;i<=n;i++)
				if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
					r=i;
					if(l==-1)
						l=i;
				}
			int j=r+1;
			for(int i=1;i<l;i++){
				while(j<=n&&x[j]-x[i]<=d)
					j++;
				ans+=n-j+1;
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=1;i<=n;i++){
			l=i;
			memset(dp,0,sizeof dp);
			memset(mm,0,sizeof mm);
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[j-1]>d)
					break;
				while(x[j]-x[l]>d)
					l++;
				if(x[j]-x[i]<=d)
					dp[j]=mm[j]=1;
				else{
					for(int k=l;k<j;k++){
						if(dp[j]==0||dp[k]+1<dp[j]){
							mm[j]=mm[k];
							dp[j]=dp[k]+1;
						}else if(dp[k]+1==dp[j])
							mm[j]+=mm[k];
					}
				}
				if(mm[j]==2)
					ans++;
//				cout<<i<<" "<<j<<" "<<l<<" "<<dp[j]<<" "<<mm[j]<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

