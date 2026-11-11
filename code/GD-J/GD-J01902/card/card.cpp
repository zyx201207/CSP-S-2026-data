#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,a[500050],b[300030],ans[300030];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	memset(b,0x3f,sizeof(b));
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(b[a[j]]==inf)
				b[a[j]]=j;
			else{
				int l=b[a[j]];
				for(int k=j-1;k>=l;k--)
					b[a[k]]=inf;
				b[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
			if(b[j]!=inf){
				ans[j]++;
				b[j]=inf;
			}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
