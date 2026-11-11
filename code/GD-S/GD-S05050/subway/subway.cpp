#include<bits/stdc++.h>
using namespace std;
struct kat{
	int k,a[500001],t[500001];
};
struct rxy{
	int r,x,y,t;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=0,n=0,m=0,d=0;
	long long q=0;
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	kat k[m+1];
	rxy r[q+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i].k;
		for(int j=1;j<=k[i].k;j++){
		cin>>k[i].a[j]>>k[i].t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].r>>r[i].x>>r[i].y;
	}
	
	
	for(int i=1;i<=q;i++){
		cout<<r[i].t;
	}
	return 0;
}
