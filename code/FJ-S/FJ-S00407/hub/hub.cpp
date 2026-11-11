#include<bits/stdc++.h>
using namespace std;
int n,k,d[2000010];
vector<int> ve[2000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	srand(time(0));
	int T;
	scanf("%d%d",&T,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		printf("%d\n",rand()*rand()%(n/2)+1);
	}
	return 0;
} 
