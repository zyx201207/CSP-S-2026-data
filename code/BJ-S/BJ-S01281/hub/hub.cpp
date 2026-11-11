#include<bits/stdc++.h>
using namespace std;
int c,t,x,y;
int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
		}
		printf("%d\n",(n/2-k)/2+1);
	}
	return 0;
}