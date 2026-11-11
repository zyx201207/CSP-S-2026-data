#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,w[505];
struct node{
    int k,a[500005],t[500005];
}r[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>r[i].k;
		for(int j=1;j<=r[i].k;j++){
		    cin>>r[i].a[j]>>r[i].t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int z=(x+y)/2;
		cout<<w[x]+r[z].t[x]+r[z].t[y]+w[y]<<"\n";
	}
	return 0;
}
