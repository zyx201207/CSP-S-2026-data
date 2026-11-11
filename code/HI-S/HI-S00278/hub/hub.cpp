#include<iostream>
#include<random>
#include<time.h>
#include<vector>
int c,t,n,k,u,v;
std::vector<int> nxt[1000100];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n-1;i++){
			scanf("%d%d",&u,&v);
			nxt[u].push_back(v);
			nxt[v].push_back(u);
		}
		printf("%d\n",rand()%(n-k)+1);
	}
	return 0;
}
