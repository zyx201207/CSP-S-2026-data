#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,d,ans,g[5003][5003];
ll x[5003],f[5003][5003];
inline ll read(){
	ll x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f; 
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t;
	cin>>t;
	ll gap;bool check;
	while(t--){
		ans=0;
		cin>>n>>d;
		gap=0;check=1;
		for(int i=1;i<=n;i++){
			x[i]=read();
			if(i==2) gap=x[i]-x[i-1];
			else if(i>=2){
				if(gap!=x[i]-x[i-1]){
					check=0;
				}
			}
		}
		if(check){
//			cout<<gap<<'\n';
			for(int i=3;i<=n-1;i++){
				if(d>=i*gap){
					ans+=n-i;
				}
			}
			if(ans!=0){
				cout<<ans<<'\n';
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=LONG_LONG_MAX;
				g[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			f[i][i]=0;
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					f[i][j]=f[j][i]=x[j]-x[i];
//					g[i][j]++;g[j][i]++;
				}
				else break;
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<i<<' '<<j<<' '<<f[i][j]<<'\n';
//			}
//		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(f[i][k]==LONG_LONG_MAX||f[k][j]==LONG_LONG_MAX) continue;
					if(f[i][j]>f[i][k]+f[k][j]){
						f[i][j]=f[i][k]+f[k][j];
						if(f[i][j]!=LONG_LONG_MAX){
							g[j][i]++;
							g[i][j]++;
						}
					}
				}
			}
		}
//		cout<<f[1][1]<<'\n';
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cout<<f[i][j]<<' '<<g[i][j]<<'\n';
				if(g[i][j]>1) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
out:
1
2
*/
}

