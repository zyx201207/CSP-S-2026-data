#include<bits/stdc++.h>
using namespace std;
int C,n,m,d,q;
int bs=0;
const int N=2000005;
long long w[N];
struct cz{
	int c,z,j;
}a[N];
int bcj[N];
bool cmp(cz b,cz c){ return b.j<c.j; }
int find(int x){
	if(bcj[x]==x) return x;
	return find(bcj[x]);
}
map<int,int[N]> jl,jl2;
int findjl(int x,int zjl){
	if(bcj[x]==x) return zjl;
	return findjl(bcj[x],zjl+jl[x][bcj[x]]);
}
void zd(){
	for(int i=1;i<=m;i++) bcj[i]=i;
	sort(a+1,a+1+bs,cmp);
	for(int i=1;i<=bs;i++){
		if(find(a[i].c)!=find(a[i].z)){
			jl[a[i].z][a[i].c]=a[i].j;
			jl[a[i].c][a[i].z]=a[i].j;
			a[i].c=a[i].z;
		}
	}
}
void cz(int x,int y){
	long long num=w[x]+w[y]+jl2[x][y]+jl2[y][x];
	num+=findjl(x,0)+findjl(x,0);
	printf("%d\n",num);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=0;i<n;i++){
		int k;
		int gqls,gqsj;
		scanf("%d",&k);
		scanf("%d%d",&gqls,&gqsj);
		jl2[k][1]=gqsj;
		for(int j=2;j<=k;j++){
			int ls;
			scanf("%d%d",&ls,&jl2[k][j]);
			a[++bs].c=gqls;
			a[bs].z=ls;
			a[bs].j=gqsj+jl2[k][j];
			gqsj=jl2[k][j];
			gqls=ls;
		}
	}
	zd();
	for(int i=0;i<q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		cz(x,y);
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
