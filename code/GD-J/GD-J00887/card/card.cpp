#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 +5;
const int M = 3e5 + 5;
int n,m, s[N];
stack<int> st;
int f[M], fx[M];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>s[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=n;j++) {
			int x = s[j];
			st.push(x);
			f[x] ++;
			if(f[x] > 1) {
				st.pop();
				f[x] --;
				while(st.top() != x) {
					f[st.top()] --;
					st.pop();
				}
			}
		}
		for(int k=1;k<=m;k++) {
			if(f[k]) fx[k] ++;
		}
		memset(f, 0, sizeof(f));
		while(!st.empty()) st.pop();
	}
	for(int i=1;i<=m;i++) {
		cout<<fx[i]<<' ';
	}
	return 0;
}
