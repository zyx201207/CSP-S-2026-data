//GZ-S00075 唐文博
#include<bits/stdc++.h>
using namespace std;
const int N=80;
int a,b,c,s,d,w[N];
int z[N][N],t[N][N],n,m;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c>>s>>d;
	for(int i=1;i<=c;i++) cin>>w[i];
	for(int i=1;i<=a+2;i++){
		int k; cin>>k;
		for(int j=1;j<=k;k++) cin>>z[i][j]>>t[i][j];
	}
	for(int i=1;i<=d;i++){
		cin>>n>>m;
		int k=0;
		for(int i=n;i<=m;i++){
			for(int j=n;j<=m;j++){
				k+=t[i][j];
			}
		}
		cout<<w[n]+k+w[m]<<endl;
	}
}
