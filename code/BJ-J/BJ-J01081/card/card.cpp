#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=500020;
int a[maxn];
int cnt[300020],cnt1[300020];
bool vis[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int t=1;t<=n;t++){
		for(int i=1;i<=m;i++){
			cnt[i]=0;
		}
		for(int i=1;i<=n;i++){
			vis[i]=1;
		}
		for(int i=t;i<=n;i++){
			cnt[a[i]]++;
			if(cnt[a[i]]>=2){
				bool flag=1;
				for(int j=1;j<i;j++){
					if(vis[j] && a[j]==a[i]){
						flag=0;
					}
					if(!flag){
						if(vis[j]){
							cnt[a[j]]--;
							vis[j]=0;
						}
						
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			cnt1[i]+=cnt[i];
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt1[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}