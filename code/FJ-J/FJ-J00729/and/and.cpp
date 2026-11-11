#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=m;i++) a[1]&=a[i];
	printf("%d",a[1]);
	return 0;
}
