#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N],b[M],c[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(c,0,sizeof(c));
		stack<int> st;
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]==1)
			{
//				cout<<1<<endl;
				int t=st.top();
				st.pop();
				while(t!=a[j]&&!st.empty())
				{
					t=st.top();
					st.pop();
				}
			}
			c[a[j]]=1;
			st.push(a[j]);
		}
		while(!st.empty())
		{
//			cout<<st.top()<<endl;
			b[st.top()]++;
			st.pop();
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}

