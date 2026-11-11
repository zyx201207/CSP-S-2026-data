#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],s[500005];
bool vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int k=1;k<=n;k++){
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		for(int i=k;i<=n;i++){
			s[a[i]]++;
			if(b[a[i]]!=0){
				for(int j=b[a[i]];j<=i-1;j++){
					if(vis[j]==0)s[a[j]]--;
					vis[j]=1;
					b[a[j]]=0;
				}
			}
			b[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",s[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
