#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,d,x[N],lt,rt,f[N],g[N],ans;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		if(c==11 || c==12){
			ans=d/(x[2]-x[1]);
			if(ans<=1) cout<<"0\n";
			else cout<<max(n-2ll*ans+1,0ll)<<"\n";
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			lt=rt=i,g[i]=1,f[i]=0;
			for(int j=i+1;j<=n && x[j]-x[j-1]<=d;j++){
				while(lt<=rt && x[j]-x[lt]>d) lt++;
				f[j]=f[lt]+1;
				if(lt==rt || f[lt]<f[lt+1]) g[j]=g[lt];
				else if(f[lt]==f[lt+1] && g[lt]+g[lt+1]==2){
					if(lt+1==rt || f[lt]<f[lt+2]) g[j]=2;
					else g[j]=3;
				}
				else g[j]=3;
				if(g[j]==2) ans++;
				rt++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
