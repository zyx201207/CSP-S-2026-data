#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m;
int a[N],b[N],e[N];
struct node{
	int v,l,r;
}c[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int t=1;
	while(t<=n){
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		for(int i=1;i<=N;i++){
			c[i].v=0,c[i].l=0,c[i].r=0;
		}
		int tot=0,cnt=0;
		int pa=a[t];
		for(int i=t;i<=n;i++){
			if(d[a[i]].v==0){
				d[a[i]].v=tot+1;
				d[pa].r=a[i];
				c[tot+1].v=a[i];
				c[tot].r=i;
				tot++;
				cnt++;
			}
			else{
				int p=d[a[i]].v;
				d[a[i]].v=tot+1;
				c[p].r=tot+1;
				cnt=cnt-(tot-p+1)+1;
			}
			pa=a[i];
		}
		e[cnt]++;
		t++;
	}
	for(int i=1;i<=m;i++){
		cout<<e[i]<<" ";
	}
	return 0;
}
