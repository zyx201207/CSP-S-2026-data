#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500001],ans[500005];
stack<int> st;
set<int> se;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}

	if(m==1) cout<<n;
	else
	{
		for(int i=1;i<=n;i++)
		{
			b[a[i]]++;
			if(b[a[i]]==2)
			{
				while(st.top()!=a[i])st.pop();
				st.pop();
				b[a[i]]=1;
			}
			st.push(a[i]);		
		}
		for(int i=1;i<=n;i++)
		{
			//cout<<st.top();
			se.insert(st.top()); 
			st.pop();
		}
		for(auto it:se)
		{
			ans[it]++;
		}	
		for(int i=1;i<=n;i++)
		{
			cout<<ans[i]<<" ";
			if(ans[i]!=0) cout<<ans[i]<<" "<<i<<endl;
		}

	}
	return 0;
 } 
/*
4 3
1 2 1 3
*/
