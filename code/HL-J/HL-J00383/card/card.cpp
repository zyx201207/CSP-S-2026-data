#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	int n,m,mx=0,ai=0;
	cin>>n>>m;
	vector<int>a(n),ans(m+1);
	for(int i=0;i<n;i++)
		cin>>a[i];
	while(a.size()>0)
	{
		map<int,int>mp;
		stack<int>st;
		for(int i=0;i<a.size();i++)
		{
			if(mp[a[i]])
			{
				while(st.top()!=a[i])
					st.pop();
				mp[a[i]]=0;
			}
			else
			{
				st.push(a[i]);
				mp[a[i]]=1;
			}
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
		a.erase(a.begin(),a.begin()+1);
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
