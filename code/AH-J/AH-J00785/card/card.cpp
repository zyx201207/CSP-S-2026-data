#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
ll a[500005];
ll ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(ll i = 1;i <= n;++i) cin >> a[i];
	for(ll k = 1;k <= n;++k){//枚举第几局(起始位置)
		stack<ll> st;//牌堆
		bool vis[500005] = {};//vis[i] : 当前牌堆中是否有面值为i的牌
		for(ll i = k;i <= n;++i){
			ll x = a[i];
			//之前没有放过这张牌,放进去,标记为1
			if(vis[x] == 0){
				st.push(x);
				vis[x] = 1;
			}//之前放过这张牌,
			else{//之前没有放过这张牌
				while(!st.empty()){//删除
					ll zhanding = st.top();//栈顶
					if(zhanding == x)  break;
					vis[zhanding] = 0;//取消标记
					st.pop();
				}
			}
		}
		while(!st.empty()){
			ans[st.top()] ++;//如果牌堆中还有这张牌,留有此数+1
			st.pop();
		}
	}
	for(ll i = 1;i <= m;++i) cout << ans[i] << ' ';
	
	return 0;
}
