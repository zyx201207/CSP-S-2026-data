#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
struct Road{
	int u,v;
}r[500005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=0;i<t;i++){
		int ans;
		scanf("%d%d",&n,&k);
		for(int j=1;j<n;j++){
			scanf("%d%d",&r[j].u,&r[j].v);
		}
		if(n%2==0) ans=2;
		else  ans=1;
		printf("%d\n",ans);
	}
	return 0;
}
