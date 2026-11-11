#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
long long a[2000006];
bool iq[2000006];
queue<int> q;
map<int,int> qq;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=m)
				{
					if(iq[j]==false)q.push(j);
					iq[j]=true;
				}
				else break;
			}
			while(!q.empty())
			{
				int l=q.front();
				iq[l]=false;
				q.pop();
				for(int j=l+1;j<=n;j++)
				{
					if(a[j]-a[l]<=m){
						qq[j]=qq[j]+1;
					}
					else break;
				}
			}
			for(auto ys:qq){if(ys.second==2)cnt++;}
			qq.clear();
		}
		cout<<cnt<<endl;
	}
}
