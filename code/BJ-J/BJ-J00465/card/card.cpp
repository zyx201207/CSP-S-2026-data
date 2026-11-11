/*
11:20 开T4
11:23 思考无果，尝试暴力，预计48
11:39 暴力0分
11:47 暴力48分
11:51 发现文件读写没写，改正
*/
#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
bool vis[300005];
int ans[300005];
stack < int > st;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	// freopen("card1.in","r",stdin);
	// freopen("card1.out","w",stdout);

	// freopen("card2.in","r",stdin);
	// freopen("card2.out","w",stdout);

	// freopen("card3.in","r",stdin);
	// freopen("card3.out","w",stdout);

	// freopen("card4.in","r",stdin);
	// freopen("card4.out","w",stdout);

	// freopen("card5.in","r",stdin);
	// freopen("card5.out","w",stdout);
	// 挂了

	// freopen("card6.in","r",stdin);
	// freopen("card6.out","w",stdout);
	// 挂了
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(vis[a[j]]){
				while(st.top() != a[j]){
					vis[st.top()] = 0;
					st.pop();
				}
				st.pop();
			}
			vis[a[j]] = 1;
			st.push(a[j]);
		}
		while(st.size()){
			vis[st.top()] = 0;
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}