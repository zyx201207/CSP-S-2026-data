#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[300010];
int s[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(b,-1,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==-1){
				b[a[j]]=j-i+1;
			}
			else{
				for(int k=1;k<=m;k++){
					if(b[k]>b[a[j]]) b[k]=-1;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]!=-1){
				s[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",s[i]);
	return 0;
}
