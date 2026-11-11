#include<bits/stdc++.h>
#define int long long
using namespace std;
int stk[500005],top;
int n,m,a[500005];
bool vis[300005];
int cnt[300005];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;++i)
		scanf("%lld",&a[i]);
	if(n <= 500){
		for(int _ = 1;_ <= n;++_){
			for(int i = _;i <= n;++i){
				if(vis[a[i]]) while(vis[a[i]]) vis[stk[top--]] = false;
				stk[++top] = a[i];
				vis[a[i]] = true;
			}
			for(int i = 1;i <= m;++i)
				if(vis[i])
					cnt[i]++,vis[i] = false;
			top = 0;
		}
		for(int i = 1;i <= m;++i)
			printf("%lld ",cnt[i]); 
	}
	else
		for(int i = 1;i <= m;++i)
			printf("%lld ",upper_bound(a + 1,a + n + 1,i) - a - 1);
    return 0;
}

