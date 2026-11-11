#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int vis[100005],ans[100005],top=0;
vector<int> v;
int main()
{
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(vis[a]==0)
		{
			v.push_back(a);
			vis[a]++;
			top++;
//			ans[a]++;
		}
		else
		{
			while(!v.empty())
			{
				if(v.back()==a) 
				{
					vis[v.back()]--;
					v.pop_back();
					top--;
					break;
				}
				vis[v.back()]--;
				v.pop_back();
				top--;
			}
			v.push_back(a);
			vis[a]++;
			top++;
//			ans[a]++;
		}
		for(int k=0;k<=top-1;k++)
		{
			
			ans[top]++;
		}
	
	}
	for(int i=1;i<=m;i++)
	{	
		cout<<ans[i]<<" ";
	}
	return 0;
}
