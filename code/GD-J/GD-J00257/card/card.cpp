#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 5010;
int a[N],vis[N],lft[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int x = 1;x<=n;x++){
			stack<int>st;
			for(int i = x;i<=n;i++){
				if(vis[a[i]]==1){
					while(st.top()!=a[i]){
						vis[st.top()]--;
						st.pop();
					}
				}
				else {
					st.push(a[i]);
					vis[a[i]]++;
				}
			}
			while(!st.empty()){
				int ttt = st.top();
				vis[ttt] = 0; 
				st.pop();
				lft[ttt]++;
			}
		}
		for(int i = 1;i<=m;i++){
			cout<<lft[i]<<" ";
		} 
		cout<<"\n";
	}
	return 0;
}
