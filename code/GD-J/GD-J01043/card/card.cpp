#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,m,a[N],ans[N];
bool b[N];
stack<long long> st;
void solve()
{
	cin>>n>>m; for(int i=1;i<=n;++i) cin>>a[i];
	for(int t=1;t<=n;++t)
	{
		for(int i=t;i<=n;++i)
		{
			if(b[a[i]]) while(!st.empty()&&st.top()!=a[i]) b[st.top()]=0,st.pop();
			else st.push(a[i]),b[a[i]]=1;
		}
		while(!st.empty()) ++ans[st.top()],st.pop();
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<" "; 
	cout<<"\n";
	return;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
} 
