#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+10;
int a[MAXN];
int ans[MAXN];
int n, m;
stack<int> s;
bool flag[MAXN];
int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    memset(ans,0,sizeof(ans));
    memset(flag,0,sizeof(flag));
    
    cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i ++) {
		memset(flag,0,sizeof(flag));
		for(int j = i; j <= n; j ++) {
			if(!flag[a[j]]) {
				s.push(a[j]);
				flag[a[j]] = 1;
			} else {
				while(s.top() != a[j]) {
				    flag[s.top()] = 0;
					s.pop();
				}
//				s.push(a[j]);
			}
		}
		
		while(!s.empty()) {
			int x = s.top();
			ans[x] ++;
			s.pop();
		}
	}
	
	for(int i = 1; i <= m; i ++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}
