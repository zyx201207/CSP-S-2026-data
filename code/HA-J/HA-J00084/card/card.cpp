#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[300010],ans[300010];
int p[300010],b[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++) p[j] = 0;
		int cnt = 0;
		for (int j = i;j <= n;j++){
			if (p[a[j]] == 0){
				b[++cnt] = a[j];
				p[a[j]] = cnt;
			}
			else{
				for (int k = cnt;k > p[a[j]];k--){
					p[b[k]] = 0;
				}
				cnt = p[a[j]];
			}
		}
		for (int j = 1;j <= cnt;j++){
			ans[b[j]]++;
		}
	}
	for (int i = 1;i <= m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
