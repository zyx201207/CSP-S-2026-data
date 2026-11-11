#include<iostream>
using namespace std;
int a[200010], use[200010];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, ans=0;
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)scanf("%d", &a[i]);
	for(int j=29;j>=0;j--){
		int sum=0;
		for(int i=1;i<=n;i++)if(!use[i])sum+=a[i]>>j&1;
		if(sum<m)continue;
		ans|=1<<j;
		for(int i=1;i<=n;i++)if(!(a[i]>>j&1))use[i]=1;
	}
	printf("%d", ans);
	return 0;
}
