#include<bits/stdc++.h>
using namespace std;
int maxn=-1901928;
int a[100086];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,andk;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		andk=a[i];
		for(int j=i+1;j<=m;j++){
			andk&=a[j];
		}
	}
	maxn=max(andk,maxn);
	printf("%d",maxn);
	return 0;
}