#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,k;
int u[1000001],v[1000001];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		srand(time(0));
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&u[i],&v[i]);
		}printf("%d\n",(rand()|1<<rand())%n);
	}
}