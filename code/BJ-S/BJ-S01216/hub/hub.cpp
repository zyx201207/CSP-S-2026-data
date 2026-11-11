#include<bits/stdc++.h>
using namespace std;
int a,b,x,y,c[10001],d[10001],ans=2147483647;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<b;i++)
	{
		cin>>x>>y;
		ans=2147483647;
		for(int j=0;j<2*x-2;j++)
		{
			cin>>c[j];
			ans=min(ans,c[j]);
		}
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
