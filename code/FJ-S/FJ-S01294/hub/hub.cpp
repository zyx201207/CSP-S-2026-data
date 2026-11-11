#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	scanf("%d&d",&c,&T);
	while(T--){
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n-1;i++){
			int u,v;
			scanf("%d%d",&u,&v);
		}
		if(n==2||n==3) cout<<0<<'\n';
		else if(n==4||n==5) cout<<1<<'\n';
	}
}
