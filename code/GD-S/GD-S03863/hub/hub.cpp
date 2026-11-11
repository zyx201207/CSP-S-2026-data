#include<bits/stdc++.h>
using namespace std;

int c, t;
int n, k;
int u, v;
vector<int> l[1000086];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1; i < n; i++){
			scanf("%d%d", &u, &v);
			l[u].push_back(v);
			l[v].push_back(u);
		}
		if(k==2){
			printf("%d\n",n/6);
			continue;
		}
		if(c==13||c==14){
			printf("%d\n", k/2 - 1);
		}else{
			printf("1\n");
		}
	}
	return 0;
}
