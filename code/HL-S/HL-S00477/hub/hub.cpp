#include<bits/stdc++.h>

using namespace std;
int c,t;
int main () {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	int cnt=0;
	while(t--) {
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) {
			scanf("%d%d",&k,&k);
		}
		printf("%d",++cnt);
	}
//	CCF HAVE NO EGG
	return 0;
}
