#include "bits/stdc++.h"
using namespace std;
#define int long long
int a[5005],f[5005],dist[5005],lst[5005];
signed main(void){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++) 
				if((a[i]-a[j])<=d){lst[i]=j;break;}
		int ans=0;
		for(int S=1;S<=n;S++){
			for(int i=1;i<=n;i++) dist[i]=1e9,f[i]=0;
			dist[S]=0;
			for(int i=S+1;i<=n;i++) dist[i]=dist[max(S,lst[i])]+1;
			f[S]=1;
			for(int T=S+1;T<=n;T++){
				for(int i=S;i<T;i++)
					if((a[T]-a[i])<=d){
						if((dist[i]+1)==dist[T]){
							f[T]+=f[i];
							if(f[T]>2) break; 
						}else break;
					}
				if(f[T]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
}
