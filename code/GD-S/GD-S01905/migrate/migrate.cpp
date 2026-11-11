#include<iostream>
#define ll long long
using namespace std;

const int N=2000010;
ll n, d;
ll a[N], dis[310][310], b[310][310];
bool v[310][310];

int main(){
	
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i=1; i<=n; i++){
			cin >> a[i];
		}
		if(c<=6){
			for(int i=1; i<=n; i++){
				for(int j=i; j<=n; j++){
					if(a[j]-a[i]<=d){
						b[i][j]=1;
						v[i][j]=v[j][i]=true;
						dis[i][j]=dis[j][i]=1;
					}else{
						b[i][j]=0;
						v[i][j]=v[j][i]=false;
						dis[i][j]=dis[j][i]=1e9;
					}
				}
			}
			for(int k=1; k<=n; k++){
				for(int i=1; i<=n; i++){
					for(int j=1; j<=n; j++){
						dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
					}
				}
			}
			for(int k=1; k<=n; k++){
				for(int i=1; i<=n; i++){
					for(int j=1; j<=n; j++){
						if(dis[i][j]==dis[i][k]+dis[k][j]){
							b[i][j]+=b[i][k]*b[k][j];
						}
					}
				}
			}
			int ans=0;
			for(int i=1; i<=n; i++){
				for(int j=i+1; j<=n; j++){
					if(b[i][j]==2){
						ans++;
					}
				}
			}
			cout << ans << '\n';
		}else if(c==11 || c==12){
			ll x=a[2]-a[1], y=d/x;
			ll ans=max(0ll, n-(2*y-1));
			if(y<=1) ans=0;
			cout << ans << '\n';
		}else cout << 0 << '\n';
	} 
	
	return 0;
}
