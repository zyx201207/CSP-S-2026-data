#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;

//card

int n,m;
int vis[MAXN];//记录桌面上有没有点数为i的排 
int cnt[MAXN];//记录有多少局桌面上剩下i点数 
int a[MAXN];
int sum[MAXN];
int baoli[MAXN];//暴力特殊情况A 
stack <int> st;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	bool flag = true;
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		sum[a[i]]++;
		if(i > 1 and a[i] < a[i - 1]) flag = false;
	}
	
	if(m == 2) {
		cout << sum[1] << ' ' << sum[2];
		return 0;		
	}
	
	if(flag) {
		for(int i = n;i >= 1;i--) {
			baoli[a[i]] = max(baoli[a[i]],i);	
		}
		for(int i = 1;i <= m;i++) {
			cout << baoli[i] << ' ';	
		} return 0;
	}
	
	int s = n;
	while(s--) {
		memset(vis,0,sizeof vis);
		for(int i = n - s;i <= n;i++) {
			int x = a[i];
			if(vis[x] == 0) {
				vis[x]++;
				st.push(x);
			} else {
				while(!st.empty() and st.top() != x) {
					vis[st.top()]--;
					st.pop();
				}
			}
		}
		while(!st.empty()) {
			cnt[st.top()]++;
			st.pop();
		}
	}
	
	for(int i = 1;i <= m;i++) {
		cout << cnt[i] << ' ';	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

