#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10,inf=1e9+1;
int b[N],D,f[310][310],num[310][310];
long long C,T,n,d,a[N],ans;
bool dc;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		dc=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=a[2]-a[1]){dc=0;break;}
		}
		if(dc){
			D=d/(a[2]-a[1]);
			if(D<=1) cout<<0<<"\n";
			else cout<<max(0ll,(n-(2*D-1)))<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) f[i][j]=inf,num[i][j]=0;
			f[i][i]=0,num[i][i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) f[i][j]=1,num[i][j]=1;
//				else{cout<<i<<" "<<j-1<<"\n";break;}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				if(i==k||f[i][k]==f[0][0]) continue;
				for(int j=1;j<=n;j++){
					if(i==j||j==k||f[k][j]==f[0][0]) continue;
					if(f[i][j]>f[i][k]+f[k][j]){
						f[i][j]=f[i][k]+f[k][j];
						num[i][j]=1;
					}else if(f[i][j]==f[i][k]+f[k][j]){
						if(num[i][j]+num[i][k]*num[k][j]>=inf) num[i][j]=inf;
						else num[i][j]=num[i][j]+num[i][k]*num[k][j];
					}
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<num[i][j]<<"\n";
				if(f[i][j]!=f[0][0]&&num[i][j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/