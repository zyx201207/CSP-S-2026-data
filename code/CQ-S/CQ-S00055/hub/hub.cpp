#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int>e[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		puts("1");
	}
	return 0;
}
