#include<bits/stdc++.h>
using namespace std;
int C; 
int n,T,a;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d",&C);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);scanf("%d",&a);
		printf("%d\n",n/a/2);
		for(int i=0;i<n*2;i++){
			scanf("%d",&a);
		}
	}
	return 0;
}
