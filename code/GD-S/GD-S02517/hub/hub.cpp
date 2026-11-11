#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,k;
int fa[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			fa[max(u,v)]=min(u,v);
		}
		int ans=0;
		printf("%d\n",ans);
	}
	return 0;
}
