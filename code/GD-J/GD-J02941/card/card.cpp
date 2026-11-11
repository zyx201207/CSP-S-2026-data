#include<bits/stdc++.h>
using namespace std;
int a[500050],ans[500050],f[500050],nxt[500050],sum[500050];
stack<pair<int,int> >st;
set<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = n;i>=1;i--){
		if(!f[a[i]])f[a[i]] = i,nxt[i] = -1;
		else nxt[i] = f[a[i]];
	}
	for(int i = n-1;i>=1;i--){
		if(a[i]==a[n]){
			s.clear();
			while(!st.empty())st.pop();
			continue;
		}
	    while(!st.empty()&&nxt[i]>=st.top().second){
			if(a[i]==st.top().first)break;
			sum[st.top().first]--;
			if(!sum[st.top().first])s.erase(st.top().first);
			st.pop();
		}
	    st.push(make_pair(a[i],i));
	    s.insert(a[i]);
	    sum[a[i]]++;
	    for(auto it:s)ans[it]++;
	}
	ans[a[n]] = n;
	for(int i = 1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
