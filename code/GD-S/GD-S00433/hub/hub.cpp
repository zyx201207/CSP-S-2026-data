#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	scanf("%d %d",&t,&t);
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d %d",&x,&y);
		}
		n>>=1;
		if(m==1){
			printf("%d\n",n/2+1);
		}else{
			int k=((n+1)/2-(m+1)/2);
			printf("%d\n",(k+1)/2+1);
		}
	}
	return 0;
}
