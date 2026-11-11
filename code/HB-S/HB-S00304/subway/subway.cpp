#include <bits/stdc++.h>
using namespace std;

long long name,n,m,d,q;
long long w[(int)5e5+10];

struct node{
	long long station,time;
};

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&name,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		
	}
	while(p--){
		printf("%lld",w[p]);
	}
	return 0;
}
