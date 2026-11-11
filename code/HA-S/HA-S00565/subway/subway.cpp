#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int M=1005;
const int D=25;
struct station{
	int w;
	int d=0;
	int t[N];
	int l[D];
	int near[D][2];
	bool vis=0;
};
struct line{
	int k;
	int a[M];
};
struct node{
	int x;
	ll t;
	int l;
};
station sta[M];
line ln[N];
int c,n,m,d,p;
ll bfs(int x,int y,ll t,int l){
	queue<node>qu;
	qu.push({x,0,l});
	ll minx=1e14;
	while(!qu.empty()){
		node nf=qu.front();
		qu.pop();
		if(nf.x==y) minx=min(minx,nf.t+t);
		for(int i=1;i<=sta[nf.x].d;i++){
			int dx1=sta[nf.x].near[sta[nf.x].l[i]][1];
			int dx2=sta[nf.x].near[sta[nf.x].l[i]][2];
			if(sta[nf.x].d==1){
				if(dx1!=0&&(!sta[dx1].vis))qu.push({dx1,nf.t,nf.l});
				if(dx2!=0&&(!sta[dx2].vis))qu.push({dx2,nf.t,nf.l});
			}else{
				if(dx1!=0&&(!sta[dx1].vis))qu.push({dx1,nf.t+sta[nf.x].t[nf.l]+sta[nf.x].t[sta[nf.x].l[i]],sta[nf.x].l[i]});
				if(dx2!=0&&(!sta[dx2].vis))qu.push({dx2,nf.t+sta[nf.x].t[nf.l]+sta[nf.x].t[sta[nf.x].l[i]],sta[nf.x].l[i]});
			}
			if(dx1!=0) sta[dx1].vis=1;
			if(dx2!=0) sta[dx2].vis=1;
		}
	}
	return minx;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++){
		scanf("%d",&sta[i].w);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&ln[i].k);
		for(int j=1;j<=ln[i].k;j++){
			scanf("%d%d",&ln[i].a[j],&sta[ln[i].a[j]].t[i]);
			sta[ln[i].a[j]].l[d++]=i;
			if(j!=1) sta[ln[i].a[j]].near[i][1]=ln[i].a[j-1];
			else sta[ln[i].a[j]].near[i][1]=0;
			sta[ln[i].a[j-1]].near[i][2]=ln[i].a[j];
		}
	}
	while(p--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll t=sta[x].w+sta[y].w;
		t=bfs(x,y,t,sta[x].l[1]);
		printf("%d\n",t);
	}
	return 0;
}
