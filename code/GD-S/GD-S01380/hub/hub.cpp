#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T,x,y,n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n-1;i++)
			scanf("%lld%lld",&x,&y);
		printf("%lld\n",k-1);
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
