#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int const N = 5005;
int a[N][N];
int x[N];
int ans;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c!=11&&c!=12){
		//  ):
		while(t--){
			cin>>n>>d;
			ans=0;
			memset(x,sizeof(x),0);
			memset(a,sizeof(a),0);
			for(int i=1; i<=n; i++)
				cin>>x[i];
			for(int i=1; i<=n; i++){
				for(int j=i; j<=n; j++){
					if(x[j]-x[i]<=d)
						a[i][j]++;
				}
			}
			for(int leng=2;leng<=n;leng++){
				for(int i=1; i<=n-leng; i++){
					for(int p=i; p<=i+leng; p++){
						a[i][i+leng] += a[i][p]*a[p][i+leng];
					}
				}
			}
			for(int i=1; i<=n; i++){
				for(int j=i; j<=n; j++){
					if(a[i][j]==2)
						ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	else if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			memset(x,sizeof(x),0);
			for(int i=1; i<=n; i++){
				cin>>x[i];
			}
			int m = x[2]-x[1];
			if(d<2*m){
				cout<<0<<endl;
			}
			else if(d>=2*m){
				cout<<n-3<<endl;
			}
		}
	}
	return 0;
}
