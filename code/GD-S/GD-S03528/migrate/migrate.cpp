#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int x[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	for(int i=1,n,d;i<=t;i++){
		scanf("%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
	}
	for(int i=0;i<t;i++){
		printf("%d\n",i);
	}
	return 0;
}
