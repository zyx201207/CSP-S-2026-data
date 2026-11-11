#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5+5,N = 3e3+6;
int n,m,a[maxn],cnt[N],ans[maxn],len,pos[N],lst[maxn];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	for(int t = 1;t <= n;t++){
		len = 0;
		for(int i = t;i <= n;i++) lst[a[i]] = 0,pos[a[i]] = 0;
		for(int i = n;i >= t;i--){
			lst[i] = pos[a[i]];
			pos[a[i]] = i;
		}
//		if(t == 1){
//			for(int i = t;i <= n;i++){
//				cout << a[i] << " " << lst[i] << "\n";
//			}
//		}
		bool flag = 0;
		for(int i = t;i <= n;){
			if(i > n) break;
			if(!flag) ans[++len] = a[i];
			if(lst[i] != 0) i = lst[i],flag = 1;
			else i++,flag = 0;
		}
		for(int i = 1;i <= len;i++){
			cnt[ans[i]]++;
//			cout << ans[i] << " ";
		}
//		cout << "\n";
	}
	for(int i = 1;i <= m;i++) printf("%lld ",cnt[i]);
	printf("\n");
	return 0;
}
