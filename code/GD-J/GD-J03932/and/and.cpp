#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	sort(a + 1,a + n + 1);
//	printf("%d %d\n",a[n],a[n - 1]);
	for(int i = n - 1;i >= n - m + 1;i--){
		a[n] &= a[i];
	}
	printf("%d",a[n]);
}
//Trick||Treat!
