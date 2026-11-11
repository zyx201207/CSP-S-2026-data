#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10,M = 3e5+10;
int a[N],ans[M],n,m;
stack<int> st;
bool f[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		memset(f,0,sizeof(f));
		for(int j = i;j<=n;j++){
			if(!f[a[j]]){
				st.push(a[j]);
				f[a[j]] = true;
			}else{
				while(st.top()!=a[j]){
					int t = st.top();
					f[t] = false;
					st.pop();
				}
				int t = st.top();
				f[t] = false;
				st.pop();
				st.push(a[j]);
				f[a[j]] = true;
			}
		}
		while(!st.empty()){
			int h = st.top();
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i = 1;i<=m;i++){
		cout << ans[i] << ' '; 
	}
	return 0;
} 
