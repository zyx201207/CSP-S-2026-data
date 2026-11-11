#include<bits/stdc++.h>
using namespace std;
int b[500005],c[300005],bo[500005],ans[300005],a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,i,j,m,k;
	memset(ans,0,sizeof(ans));
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n;i++){
		memset(bo,0,sizeof(bo));
		memset(c,0,sizeof(c));
		for(j=i;j<=n;j++){
			if(c[b[j]]==0)
				a[b[j]]=j;
			else
				for(k=a[b[j]];k<j;k++)
					bo[k]++,c[b[k]]=0;
			c[b[j]]=1-c[b[j]];
		}
		for(j=i;j<=n;j++)
			if(bo[j]==0)
				ans[b[j]]++;
	}
	for(i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
