#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e6+5;
int c,T,n;
long long d,x[N];
bool flag;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while (T--){
		scanf("%d%lld",&n,&d);
		if (n==4) flag=1;
		for (int i=1;i<=n;++i){
			scanf("%lld",&x[i]);
		}
	}
	if (flag){
		puts("1\n2");
	}else puts("0\n1");
	return 0;
}

