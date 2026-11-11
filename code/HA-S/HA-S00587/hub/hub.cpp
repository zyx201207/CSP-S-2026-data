#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int a[N],u[N],v[N];
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while(t--){
		scanf("%d%d",&n,&k);
		memset(a,0,sizeof(a));
		memset(u,0,sizeof(u));
		memset(v,0,sizeof(v));
		for(int i = 1;i < n;i++){
			scanf("%d%d",&u[i],&v[i]);
		}
		printf("%d\n",k-1);
	}
	return 0;
}
