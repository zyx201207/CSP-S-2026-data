#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],x[300005];
int ans[300005];
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		stack<int> st;
		for(int j=1;j<=m;j++)
		{
			x[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			while(!st.empty() && x[a[j]] && st.top()!=a[j])
			{
				x[st.top()]--;
				st.pop();
			}
			if(!st.empty() && st.top()==a[j])
			{
				x[st.top()]--;
				st.pop();
			}
			st.push(a[j]);
			x[a[j]]++;
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return;
}
void solve2()
{
	for(int i=1;i<=n;i++)
	{
		ans[a[i]]=max(ans[a[i]],i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return;
}
void solve3()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[n])
		ans[a[i]]++;
		else
		ans[a[i]]++,ans[a[n]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return;
}
int b[5005],js;
void solve4()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
		b[++js]=a[i];
	}
	for(int i=1;i<=js;i++)
	{
		a[i]=b[i];
	}
	for(int i=1;i<=js;i++)
	{
		stack<int> st;
		for(int j=1;j<=m;j++)
		{
			x[j]=0;
		}
		for(int j=i;j<=js;j++)
		{
			while(x[a[j]] && st.top()!=a[j])
			{
				x[st.top()]--;
				st.pop();
			}
			if(!st.empty() && st.top()==a[j])
			{
				x[st.top()]--;
				st.pop();
			}
			st.push(a[j]);
			x[a[j]]++;
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=5000)
	solve1();
	else if(m<=2)
	solve3();
	else if(m<=3000)
	solve4();
	else
	solve2();
	
	
	return 0;
}
