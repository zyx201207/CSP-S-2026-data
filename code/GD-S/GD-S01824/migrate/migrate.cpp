#include<bits/stdc++.h>
using namespace std;
int n,d;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		cout<<rand()%124*rand()%63*5+7%200;
	}
	return 0;
}
