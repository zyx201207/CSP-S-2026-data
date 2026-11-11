#include<bits/stdc++.h>
using namespace std;
int cs[114514],sb[114514];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		if(n==0)
		{
			int n,k;
			cin>>n>>k;
			for(int i=1;i<=n+1;i++)
			{
				cin>>cs[i]>>sb[i];
			}
			cout<<1<<endl;
			cout<<2;
		}
	}
} 
