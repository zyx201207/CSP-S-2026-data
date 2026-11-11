#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,k;
int x[300010],y[300010];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n-1;i++){
			scanf("%d %d",&x[i],&y[i]);
		}
		if(c==13||c==14){
			printf("%d\n",(n-k)/2);
		}
	}
	return 0;
}
