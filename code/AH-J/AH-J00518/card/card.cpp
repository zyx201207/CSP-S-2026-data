#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
bool f[300010];
int ans[300010];
int a[500010];
stack<int> st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				while(!st.empty()){
					f[st.top()]=0;
					if(a[j]==st.top()){
						st.pop();
						break;
					}
					st.pop();
				}
			}
			f[a[j]]=1;
			st.push(a[j]);
		}
		for(int j=1;j<=m;j++){
			if(f[j]==1) {
				ans[j]++;
			}
		}
		while(!st.empty()){
			f[st.top()]=0;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}//30
