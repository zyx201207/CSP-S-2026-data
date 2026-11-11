#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5,MAXM=3e5+5;
int n,m,a[MAXN],ans[MAXN],pos[MAXM];
bool lst[MAXM],p[MAXN];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>=200000){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=n;i>=1;i--)
			if(!ans[a[i]]) ans[a[i]]=i;
		for(int i=1;i<=m;i++)
			printf("%d ",ans[i]);
		return 0;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(pos,0,sizeof(pos));
		memset(lst,0,sizeof(lst));
		memset(p,0,sizeof(p));
		for(int j=i;j<=n;j++){
			if(!pos[a[j]]||lst[pos[a[j]]]==1) pos[a[j]]=j;
			else{
				for(int k=pos[a[j]];k<j;k++)
					lst[k]=1;
				pos[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++)
			if(!lst[j]&&!p[a[j]])
				ans[a[j]]++,p[a[j]]=1;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
/*
4 3
1 2 1 3

4 3
3 1 2 1

10 3
3 1 2 1 3 2 3 1 2 1

3 1
*/
