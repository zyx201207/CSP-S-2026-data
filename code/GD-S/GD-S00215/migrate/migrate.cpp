#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
namespace s1{
int a[310][310],b[310][310];//最短路，方案数 
int n,d,x[310];
void solve(){
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) a[i][j]=0x3f3f3f3f3f3f3f3fll,b[i][j]=0;
		for(int i=1;i<=n;++i) cin>>x[i];
		for(int i=1;i<=n;++i) a[i][i]=1,b[i][i]=1;
		for(int i=1;i<=n;++i) for(int j=i+1;j<=n&&x[j]-x[i]<=d;++j) a[i][j]=2,b[i][j]=1;
		for(int k=1;k<=n;++k){
			for(int i=1;i+k<=n;++i){
				for(int j=i+1;j<k+i;++j){
					if(x[j]-x[i]>d||x[i+k]-x[j]>d) continue;
					if(a[i][j]+a[j][i+k]-1>a[i][i+k]) continue;
					if(a[i][j]+a[j][i+k]-1<a[i][i+k]){
						a[i][i+k]=a[i][j]+a[j][i+k]-1;
						b[i][i+k]=0;
					}
					b[i][i+k]+=b[i][j]*b[j][i+k];
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(b[i][j]==2) ++cnt;
			}
		}
		cout<<cnt<<endl;
	}
}
};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	if(c<=6) s1::solve();
	return 0;
}//24
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
