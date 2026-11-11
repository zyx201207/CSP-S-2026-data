#include <bits/stdc++.h> 
using namespace std;
int c,n,m,d,q,w[500005],k,t[500005],l,r,s,tm=999999999;
struct nd{
	int id,t;
}a[500005];
vector <pair<int,int>>q[500005]; 
int ch(int l){
	int ik;
	for(int i=0;i<(int)q[l].size();i++){
		int x=q[l][i];
		if(a[x].t<tm){
			tm=a[x].t;
			ik=a[x].id;
		}
	}
	return tm;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.in","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a[j].id,&a[j].t);
			q[i].push_back(j);
		}
	}
	while(q--){
		scanf("%d%d",&l,&r);
		int tl=ch(l),tr=ch(r);
		s=w[l]+w[r]+tl+tr;
		printf("%d",s); 
	}
	return 0;
}
