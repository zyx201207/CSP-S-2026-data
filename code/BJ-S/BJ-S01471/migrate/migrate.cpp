#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=310;
ll dp[N][N],w[N][N];
ll a[N],lst[N],nxt[N];
ll cnt=0;
void to(int l,int r,int step){
	if(step==0&&l==r){
		cnt++;
		return;
	}else if(!step)return;
	for(int i=l+1;i<=nxt[l];i++){
		to(i,r,step-1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,T;
	cin>>c>>T;
	while(T--){
		ll n,d;
		cin>>n>>d;
		memset(dp,0,sizeof(dp));
		memset(w,0,sizeof(dp));
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			ll k=i;
			lst[i]=1;
			while(a[k]-a[i]<d&&k<n)k++;
			if(a[k]-a[i]>d)k--;
			lst[k]=i;nxt[i]=k;
			for(int j=i;j<=k;j++)w[i][j]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=i;k<=j;k++){
					if(w[i][k]&&w[k][j]&&!w[i][j])
						w[i][j]=w[i][k]+w[k][j];
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(w[i][j]<2)continue;
				cnt=0;
				to(i,j,w[i][j]);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
