#include<bits/stdc++.h>
using namespace std;
int cid,T,n,m; 
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++) scanf("%*d%*d");
	if(n==m) return printf("0\n"),void();
	n=n/2+2;
	printf("%d\n",max(1,(n-m+3)/4));
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&cid,&T);
	while(T--) solve();
	return 0;
}

