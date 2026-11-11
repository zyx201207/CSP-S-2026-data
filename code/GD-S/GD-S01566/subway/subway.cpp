#include<bits/stdc++.h>
using namespace std;
long long t=0;
struct node{
	int u,v,xh,ht[52];
}s[100005];
int k[100005];
void travel(node a){
	t+=a.xh;
	t+=a.v;
	t+=a.ht[1];
	t+=a.ht[2];
	t+=a.ht[3];
	t+=a.ht[4];
	t+=a.ht[5];
	t+=a.ht[6];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q; cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i].xh;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>s[j].u>>s[j].ht[i];
			if(j>1) s[j-1].v=s[j].u;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		t=0;
		travel(s[x]);
		cout<<t<<endl;
	}
	return 0;
}
