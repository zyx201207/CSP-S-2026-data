#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(m==1)printf("%d",a[n]);
	else printf("%d",a[n-m+1]);
	return 0;
}
