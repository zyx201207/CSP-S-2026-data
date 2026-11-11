#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int id[N];
set<string> st;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1)
	{
		long long res=0;
		for(int i=1;i<=n;i++)res=max(res,a[i]);
		cout<<res<<endl;
	}
	else if(m==n)
	{
		long long res=a[1];
		for(int i=2;i<=n;i++)res=(res&a[i]);
		cout<<res<<endl;
	}
	else if(m==2)
	{
		long long ans=0;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		for(int i=1;i<=n;i++)id[i]=i;
		do
		{
			string str="";
			for(int i=1;i<=m;i++)str+=to_string(id[i]);
			st.insert(str);
		}while(next_permutation(id+1,id+n+1));
		long long ans=0;
		for(auto x:st)
		{
			long long res;
			for(int i=0;i<x.size();i++)
			{
				if(i==0) res=a[x[0]-'0'];
				else res=(res&a[x[i]-'0']);
			}
			ans=max(ans,res);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}