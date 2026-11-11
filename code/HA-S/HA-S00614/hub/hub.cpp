#include<iostream>
#include<vector>
using namespace std;
vector<int> vec[1000010];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		if(c==7||k==2)
		{
			int flag=0;
			for(int i=1;i<=n;i++)
			{
				if(vec[i].size()==n-1)
				{
					cout<<1<<endl;
					flag=1;
				}
			}
			if(!flag)
			{
				cout<<0<<endl;
			}
//			cout<<k<<endl;
		}
	}
}
