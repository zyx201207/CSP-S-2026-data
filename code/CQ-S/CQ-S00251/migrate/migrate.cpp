#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,INF=0x3f3f3f3f3f3f3f3f;
int c,t,n,d,a[N],dp[N],f[N],l[N],r[N],sum1[N],sum2[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>> c >> t;
	while(t--){
		cin>> n >> d;
		for(int i=1;i<=n;i++) cin>> a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(dp,0x3f,sizeof(dp));
			memset(f,0,sizeof(f));
			memset(l,0,sizeof(l));
			memset(r,0,sizeof(r));
			memset(sum1,0,sizeof(sum1));
			memset(sum2,0,sizeof(sum2));
			dp[i]=0,f[i]=1,l[i]=i,sum2[i]=1;
			for(int j=i+1;j<=n;j++){
				for(int k=l[j-1];k<=j;k++){
					if(a[j]-a[k]>d) continue;
					l[j]=k;break;
				} 
			}
			for(int j=i+1;j<=n;j++){
				dp[j]=min(dp[j],dp[l[j]]+1);
			}
			for(int j=i+1;j<=n;j++){
				if(dp[j]==INF) continue;
				int l=::l[j],r=j-1,ans=-1;
				while(l<=r){
					int mid=l+r>>1;
					if(dp[mid]+1==dp[j]) l=mid+1,ans=mid;
					else r=mid-1;
				} 
				::r[j]=ans;
			}
			for(int j=i+1;j<=n;j++){
				if(!r[j]) continue;
				if(sum1[r[j]]-sum1[l[j]-1]) f[j]=-1;
				else{
					int tmp=sum2[r[j]]-sum2[l[j]-1];
					if(tmp>2) f[j]=-1;
					else f[j]=tmp;
				}
				sum1[j]=sum1[j-1]+(f[j]==-1);
				if(f[j]!=-1) sum2[j]=sum2[j-1]+f[j];
				ans+=f[j]==2;
			}
		}
		cout<< ans << endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

