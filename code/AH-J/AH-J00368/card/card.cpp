#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],f[N],ans[N],p;
stack<int> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	while(p<n)
	{
		memset(f,0,sizeof(f));
		p++; 
		for(i=p;i<=n;i++)
		{
			if(f[a[i]]!=0)
			{
				f[a[i]]=0;
				bool t=0;
				while(!st.empty()&&t==0)
				{
					if(st.top()==a[i])
						t=1;
					f[st.top()]=0;
					st.pop();
					
				}
			}
			st.push(a[i]);
			f[a[i]]++;
		}
		
		while(!st.empty())
		{
			int x=st.top();
			ans[x]++;
			f[x]=0;
			st.pop();
		}
	}
	for(i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}
//Trick||Treat!
