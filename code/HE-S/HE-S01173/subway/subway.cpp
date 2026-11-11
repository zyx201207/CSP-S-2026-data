#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
const int M = 1e3+5;
long long m,c,n,d,q,ki,e,o;
long long v[N];
struct op{
	long long x;
	long long y;
}a[N];
long long g[M][M];
long long t[M][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>v[i]; 
	}
	for(int i = 1;i<=d;i++){
		cin>>ki;
		for(int j = 1;j<=ki;i++){
			cin>>g[i][j]>>t[i][j];
		}
	}
	for(int i = 1;i<=q;i++){
		cin>>a[i].x>>a[i].y;
	}
	o = 1;
	while(q--){
		cout<<v[a[o].x]+t[a[o].x][a[o].x]+t[a[o].x][a[o].y]+v[a[o].y]<<endl;
		o++;
	}
	return 0;
}
