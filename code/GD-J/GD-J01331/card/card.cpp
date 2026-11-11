#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5,M=3e5+5;
ll n,m;
ll a[N],cnt[M];
stack<ll> st;
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		vector<bool> vis(M,0);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]) {
				while(st.top()!=a[j]&&st.size()) vis[st.top()]=0,st.pop();
			}
			else {
				vis[a[j]]=1;
				st.push(a[j]);
			}
		}
		while(st.size()) cnt[st.top()]++,st.pop();
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	
	return 0;
}
