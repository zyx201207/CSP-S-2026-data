#include <bits/stdc++.h>
using namespace std;

const int N1 = 5e5+100;
const int N2 = 3e5+100;
int a[N1],b[N2],ans[N2];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for (i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	for (i = 1;i <= n;i++){
		for (j = 1;j <= m;j++) b[j] = 0;
		for (j = i;j <= n;j++){
			if (b[a[j]] == 0){
				b[a[j]] = 1;
			}else{
				for (k = j-1;k >= i;k--){
					b[a[k]] = 0;
					if (a[k] == a[j]) break;
				}
				b[a[j]] = 1;
			}
		}
		for (j = 1;j <= m;j++){
			if (b[j]) ans[j]++;
		}
	}
	
	for (i = 1;i <= m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}