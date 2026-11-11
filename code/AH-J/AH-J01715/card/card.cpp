#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
stack<int> st;
map<int,int> mp;
int a[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n<=500 && m<=200) {
		for(int i=1;i<=n;i++) cin>>a[i];
		vector<int> ans(m+5);
		for(int i=1;i<=n;i++) {
			while(!st.empty()) st.pop();
			mp.clear();
			for(int j=i;j<=n;j++) {
				if(mp[a[j]]!=0) while(!(st.top()==a[j])) {mp[st.top()]--;st.pop();}
				else {
					mp[a[j]]++;
					st.push(a[j]);
				}
			}
			for(auto j:mp) if(j.second!=0) ans[j.first]++; 
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else {
		for(int i=1;i<=n;i++) {int x;cin>>x;mp[x]++;}
		for(auto i:mp) cout<<max(i.second,i.first)<<" ";
	}
	return 0;
}
