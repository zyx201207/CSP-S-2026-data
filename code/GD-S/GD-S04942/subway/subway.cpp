#include<bits/stdc++.h>
using namespace std;
int n,c,q,m,r,k,v,d,cs,x1,x2;
const int N=500010;
int a[N][N];
long long t[N][N];
int w[N];
int x[100010],y[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cs=0;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>x[r]>>y[r];
	}
	return 0;
}
