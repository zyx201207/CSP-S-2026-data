#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+10;
int test_id,T,n,k;
vector<int>e[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&test_id,&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		for(int i = 1;i<n;i++){
			int u,v;
			scanf("%lld%lld",&u,&v);
			e[u].push_back(v),e[v].push_back(u);
		}
		if(n%2)
			printf("%lld\n",2);
		else
			printf("%lld\n",1);
	}
	return 0;
}
