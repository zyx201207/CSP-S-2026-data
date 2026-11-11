#include<bits/stdc++.h>
using namespace std;
int oi[50005],cg[50005];
int c,n,m,d,q;
int k;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(cg,0,sizeof(cg));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>oi[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,w;
			cin>>x>>w;
			cg[x]=max(w,cg[x]);
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		cout<<oi[s]+cg[s]+oi[e]+cg[e];
	}
	return 0;
}
