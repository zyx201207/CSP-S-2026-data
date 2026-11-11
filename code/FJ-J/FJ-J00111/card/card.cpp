#include<stdio.h>
const int N=5e5+5,M=3e5+5;
int a[N];
int nxt[N],vis[N];
int stk[N],top;
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=n;i>=1;i--){
		nxt[i]=vis[a[i]];
		vis[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=i;j<=n;j++){
			while(nxt[j]){
				j=nxt[j];
			}
			stk[++top]=a[j];
		}
		while(top){
			ans[stk[top--]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
