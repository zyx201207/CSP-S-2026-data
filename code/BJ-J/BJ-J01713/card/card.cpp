#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int maxm=3e5+5;
int a[maxn];
int t[maxm];
long long ans[maxm];
stack<int> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)t[j]=0;
		for(int j=i;j<=n;j++)
		{
			while(!st.empty()&&t[a[j]]>0)
			{
				t[st.top()]--;
				st.pop();
			}
			st.push(a[j]);
			t[a[j]]++;
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
