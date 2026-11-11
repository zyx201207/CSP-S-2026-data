#include<bits/stdc++.h> 
using namespace std;
int n,m,a[2000001],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=n;i>=n-m+1;i--){
		ans=(ans&a[i]);
	}
//	for(int i=1;i<=n;i++)
//		printf("%d\n",a[i]);
	printf("%d\n",ans);
	return 0;
}
