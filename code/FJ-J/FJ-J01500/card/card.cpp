#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N];
stack<int> st;
map<int,int> cnt;
map<int,bool> mp;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=n;j++) {
		mp.clear();
		for(int i=j;i<=n;i++) {
			if(mp[a[i]]) {
				while(st.top()!=a[i]) {
					mp[st.top()]=0;
					st.pop();
				}
			} else {
				st.push(a[i]);
				mp[a[i]]=1;
			}
		}
		while(!st.empty()) {
			int x=st.top();
			cnt[x]++;
			st.pop();
		}
	}
	for(int i=1;i<m;i++)
		cout<<cnt[i]<<" ";
	cout<<cnt[m];
	return 0;
}

