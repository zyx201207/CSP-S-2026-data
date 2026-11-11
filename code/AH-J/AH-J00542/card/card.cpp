#include<bits/stdc++.h>

using namespace std;


int n,m;
const int M=5e5+5;

int a[M];
deque<int>dq;
map<int,int>vis;
map<int,int>ans;
int main()
{
	freopen("card.in",".r",stdin);
	freopen("card.out",".w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;++i)
	cin>>a[i];
	for(int k=1;k<=n;++k)
	{
	 	dq.clear();
	 	vis.clear();
		for(int i=k;i<=n;++i)
		{
		
		if(!vis[a[i]])
		{
			vis[a[i]]=1;
			dq.push_back(a[i]); 
		}
		else{
			int j=i-1;
			while(j--&&!dq.empty())
				dq.pop_back();
			vis[a[i]]=0;
				dq.push_back(a[i]);
			}
		
			}
		for(auto it:dq)
		{
			ans[it]++;
			cout<<it<<" "; 
		}
			cout<<"\n";
			
		
	}			
	for(int  i=1;i<=m;++i)
		cout<<ans[i]<<" ";
	return 0;
}

