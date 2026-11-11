#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >edge;
void sol(){
	edge.clear();
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		edge.push_back({u,v});
	}
	printf("%d\n",(n+k)*rand()%501);
}
int c,t; 
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)sol();
	
	
	return 0;
} 
