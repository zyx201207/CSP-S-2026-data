#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a,a+n+1,cmp);
	printf("%d",a[m-1]);
}
