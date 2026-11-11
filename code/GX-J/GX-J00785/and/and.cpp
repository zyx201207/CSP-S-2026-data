
#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans = -1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= n-1;i++){
		for (int j = i+1;j <= n;j++){
			ans = max(a[i] & a[j],ans);
		}
	}
	printf("%d",ans);
	return 0;
}
