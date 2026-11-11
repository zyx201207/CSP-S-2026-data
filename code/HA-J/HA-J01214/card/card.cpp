#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],x[3010],mp[3010],qzh[200010];
stack<int>st;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int u=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]<u)u=INT_MAX;
		else u=a[i];
	}
	if(n<=5000) {

		for(int i=1; i<=n; i++) {
			memset(mp,0,sizeof(mp));
			for(int j=i; j<=n; j++) {
				if(mp[a[j]]) {
					while(st.size()&&st.top()!=a[j]) mp[st.top()]=0,st.pop();
					st.pop();
				}
				mp[a[j]]=1;
				st.push(a[j]);
			}
			while(st.size())x[st.top()]++,st.pop();
		}
		for(int i=1; i<=m; i++) {
			cout<<x[i]<<' ';
		}
		return 0;
	}
	if(u!=INT_MAX) {
		for(int i=1; i<=n; i++) {
			qzh[a[i]]++;
		}
		for(int i=1; i<=m; i++)qzh[i]+=qzh[i-1],cout<<qzh[i]<<' ';
		return 0;
	}
	return 0;
}
