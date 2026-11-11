#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
const int N=5e3+5;
int a[N];
void solve(){
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int ans=a[2]-a[1];
	if(ans<d)printf("%d\n",(n-(d/ans))/2);
	else puts("0");
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)solve();
	return 0;
}
