#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],cnt[N],zt[N];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(zt,0,sizeof zt);
		for(int j=i;j<=n;j++){
			if(zt[a[j]]!=0){
				int flag=j-1;
				while(a[flag]!=a[j]){
					zt[flag]=0;
					flag--;
				}
			}
			zt[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(zt[j]!=0) cnt[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}