#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e6+5;
int c,t,n,d,x[maxn],dp[maxn][2],lst[maxn],p[maxn];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int l=1,ans=0;
		for(int i=1;i<=n;i++){
			p[i]=i;
			__int128 c=x[l]+d;
			while(c<x[i]) l++,c=x[l]+d;
			if(l<i){
				int cnt=0;
				for(int j=l;j<min(l+3,i);j++)
					if(lst[j]==lst[l]) cnt++;
				if(cnt==1){
					dp[i][0]=dp[l][0]+i-l;
					dp[i][1]=dp[l][1];
					if(l<i-1){
						if(lst[l+1]-1==lst[l]){
							dp[i][1]=dp[p[l]][1];
						}
						dp[i][1]+=l-lst[l+1],dp[i][0]-=l-lst[l+1];
						if(l<i-2) dp[i][1]-=l-lst[l+2];
					}
				}
				if(cnt==2){
					dp[i][0]=i-l;
					dp[i][1]=dp[l][0];
					if(l<i-2) dp[i][1]-=l-lst[l+2];
				}
				if(cnt==3){
					dp[i][0]=i-l;
					dp[i][1]=0;
				}
//				if(!f[dp[i][1]]) f[dp[i][1]]=i;
//				if(dp[i][1]>1&&!f[2]) f[2]=dp[i][1];
			}
			else dp[i][0]=dp[i][1]=0;  
//			cout<<i<<' '<<dp[i][0]<<' '<<dp[i][1]<<'\n';
			lst[i]=l;
			if(lst[i]-1==lst[i-1]) p[i-1]=p[lst[i-1]];
			if(lst[i]==lst[i-1]) p[i-1]=0;
//			if(lst[i]==lst[i-1]) p[i-1]=0;
			ans+=dp[i][1]; 
		}
//		for(int i=1;i<=10;i++) cout<<f[i]<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
}

