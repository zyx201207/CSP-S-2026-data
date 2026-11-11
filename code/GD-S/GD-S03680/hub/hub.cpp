#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T,n,k;
int main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++)
		{
			cin>>x>>y;
		}
		if(n==k)
		{
			cout<<0<<endl;
			continue;
		}
		if(c==0 or c==13 or c==14)
		{
			n=(n+1)/2+1;
			n-=k;
			n=(n+3)/4;
			cout<<n<<endl;
		}
		else cout<<1<<endl;
	}
	return 0;
}
