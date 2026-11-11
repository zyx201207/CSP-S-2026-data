#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c,t;
int n,m;
int a[2000001];

void xie(){
	int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n-3;i++)
		if(a[i+2]-a[i]<=m && a[i+3]-a[i]>m && a[i+3]-a[i+1]<=m)
			ans++;
	printf("%d\n",ans);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
		xie();
	return 0;
}
