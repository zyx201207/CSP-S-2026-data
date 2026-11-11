#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c,T;
int n,k;
vector<int>edges[1000010];

void init(){
	for(int i=1;i<=n;i++){
		edges[i].clear();
	}
}

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		init();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		if(n%2==k%2){
			if(k==1){
				printf("%d\n",(n-1)/2);
			}else{
				int ans=(n/2-k/2)/2;
				printf("%d\n",ans);
			}
		}else{
			if(k==1){
				printf("%d\n",(n+1)/2-1);
			}else{
				int ans=(n/2-k/2)/2+1;
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
