#include<bits/stdc++.h>
using namespace std;
int const MAXN=(int)5e5+5;
int const MAXM=(int)3e5+5;
struct Node{
	int zhi;
	int id;
};
int n,m;
int a[MAXN];
int top=0;
Node b[MAXN];
int nxt[MAXN];
//~ int lst[MAXN];
int c[MAXM];
int ans[MAXM];
void F(int x){
	top=0;
	
	for(int i=x;i<=n;i++){
		b[++top].zhi=a[i];
		b[top].id=i;
		while(nxt[i]!=0){
			i=nxt[i];
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(c[a[i]]!=0){
			nxt[c[a[i]]]=i;
		}
		//~ lst[i]=c[a[i]];
		
		c[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		F(i);
		for(int j=1;j<=top;j++){
			ans[b[j].zhi]++;
			b[j].zhi=0;
			b[j].id=0;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
