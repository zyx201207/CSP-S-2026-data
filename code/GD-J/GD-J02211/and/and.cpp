#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n + 5];
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	sort(a + 1,a + n + 1,cmp);
	int ans = a[1];
	for(int i = 2;i <= m;i++){
		ans =  (ans | a[i]);
	}
	printf("%d",ans);
	return 0;
} 
