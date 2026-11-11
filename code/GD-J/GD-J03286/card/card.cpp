#include <bits/stdc++.h>
using namespace std;

int n,m,a[500001],s[500001],t,c[300001],ans[300001],aans[300001];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		t=0;
		memset(c,0,sizeof(c));
		memset(aans,0,sizeof(aans));
		for(int j=i;j<=n;j++){
			if(c[a[j]])
				t=c[a[j]];
			else
				s[++t]=a[j];
			c[a[j]]=j;
		}
		for(int j=1;j<=t;j++)
			aans[s[j]]=1;
		for(int j=1;j<=m;j++)
			ans[j]+=aans[j];
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	printf("\n");
}
