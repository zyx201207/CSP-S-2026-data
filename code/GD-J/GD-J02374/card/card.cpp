#include<bits/stdc++.h>
using namespace std;
const long long N = 500000 + 7,M = 300000 + 7;
long long n,m,x,ans[M],a[N],nxt[N];
bool f[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	for(int i = 1;i <= n;i ++) nxt[a[i]] = i;
	for(int i = 1;i <= n;i ++){
		long long l = i;
		while(l <= n){
			ans[a[l]] ++;
			if(l < nxt[a[l]]) l = nxt[a[l]];
			l ++;
		}
	}
	for(int i = 1;i <= m;i ++) cout << ans[i] << " ";
	return 0;
}
