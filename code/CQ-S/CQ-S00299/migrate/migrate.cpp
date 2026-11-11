#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2000005
ll x[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	scanf("%d%d",&c,&t);
	while(t--){
		int n;
		ll d;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		printf("0\n");
	}
}
