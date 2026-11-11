
#include <bits/stdc++.h>
using namespace std;
int n,m,a[300001],t;
int ans[300001];
int fix[500001],desk[500001],top = 0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			bool r = 1;
			for (int k = 1;k <= top;k++){
				if (a[j] == desk[k]){
					r = 0;
					top = k - 1;
					break;
				}
			}
			if (!r)
				desk[++top] = a[j];
		}
		for (int j = 1;j <= top;j++){
			fix[j] = desk[j];
		}
		t += top;
	}
	for (int i = 1;i <= m;i++){
		for (int j = 1;j <= t;j++){
			if (fix[j] == i)
				ans[i]++;
		}
	}
	for (int i = 1;i <= m;i++)
		printf("%d ",ans[i]);
	return 0;
}
