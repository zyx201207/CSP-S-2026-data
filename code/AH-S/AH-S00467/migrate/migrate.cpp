#include<bits/stdc++.h>
#define int long long
using namespace std;
int X[2000005];
int x[2000005],a[2000005],t[2000005],sum[2000005],dis[2000005];
int b[2000005],cnt;
int n,k;
int c,T;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cnt=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int N=n;
		for(int i=1;i<=N;i++){
			if((i==1||x[i]-x[i-1]>k)&&(x[i+1]-x[i]>k||i==N)){
				n--;
			}
		}
		int r=1;
		for(int i=1;i<=n;i++){
			while(x[r]-x[i]<=k&&r<=n){
				r++;
			}
			if(r==n+1){
				a[i]=n;
			}else
				a[i]=r-1;
			//cout<<a[i]<<" ";
		}
		//cout<<"\n";
		for(int i=1;i<=n;i++){
			if(a[a[i]]==a[a[i]-1]&&a[a[i]]!=a[a[i]-2]){
				b[++cnt]=i;
			}
		}
		int ans=998244353;
		b[0]=0;
		b[cnt+1]=n;
		for(int i=1;i<=cnt;i++){
			ans=min(ans,(b[i])*(n-b[i]+1));
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*

*/
