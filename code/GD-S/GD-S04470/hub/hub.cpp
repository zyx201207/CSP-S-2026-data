#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
		} 
		int m=(n-1)/2;
		if(n==k) printf("0\n");
		else if(k>=m) printf("1\n");
		else{
			int ans=n+1;
			for(int i=0;m-k-2*i>=0;i++){
				ans=min(ans,max(i,(m-k-2*i+1)/2));
			}
			printf("%d\n",ans+1);
		}
	}
	return 0;
}
