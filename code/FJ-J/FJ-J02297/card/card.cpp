#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	const int MAXN = 5000005;
	int n,m,a[MAXN],ans[MAXN] = {0};
	stack<int> s;
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	
	if(m > 200){
		for(int i = 1;i <= m;i++)
			cout << (a[i]+1)/2 << endl;
		return 0;
	}
	
	for(int i = 1;i <= n;i++) {
		bool b[MAXN] = {0};
		int d[MAXN] = {0};
			
		for(int j = i;j <= n;j++) {
			if(!b[a[j]]) {
				s.push(a[j]);
				b[a[j]] = 1;
				d[a[j]] = s.size();
			}
			else {
				while(s.size() >= d[a[j]]) {
					b[s.top()] = 0;
					s.pop();
				}
			}	
		}
		
		for(int j = 1;j <= m;j++)
			if(b[j])
				++ans[j];
	}
	
	for(int i = 1;i <= m;i++) cout << ans[i] << endl;
	return 0;
} 
