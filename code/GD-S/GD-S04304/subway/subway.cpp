#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k,a[505],t[505],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>a[j]>>t[j];
	}
	for(int i=1;i<=q;i++){
		int time=0,g,l;
		cin>>x>>y;
		g=x;
		while(g!=y){
			l=w[g]+t[g]+t[g+1];
			time+=l;
		}
	}
	cout<<time;
	return 0;	
}
