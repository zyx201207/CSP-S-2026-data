#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int c,n,m,d,q,w[N*5],k[501],a[501][501],t[501][501],x[N],y[N],ans[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;++i) cin>>w[i];
	for(int i=0;i<n;++i){
		cin>>k[i];
		for(int j=0;j<k[i];++j) cin>>a[i][j]>>t[i][j];
	}
	for(int i=0;i<q;++i) cin>>x[i]>>y[i];
	for(int i=0;i<q;++i)
		cout<<2*(w[i]+w[0]+x[i]+y[i])<<endl;
	return 0;
}
