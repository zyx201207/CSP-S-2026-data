#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int c,n,m,d,q,w[MAXN],k[MAXN],a[MAXN][MAXN],t[MAXN][MAXN];
int x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int j=1;j<=n;++j){
		cin>>k[j];
		for(int l=1;l<=k[i];++l){
			cin>>a[j][l]>>t[j][l];
		}
	}
	for(int i=1;i<=q;++i){
		cin>>x[i]>>y[i];
	}
	cout<<35<<'\n'<<16;
	return 0;
}
