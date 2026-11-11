#include<iostream>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int tmp;
		while(cin>>tmp)
		if(t%2==1)
		{
			cout<<1<<'\n';
		}else
		{
			cout<<2<<'\n';
		}
	}
	return 0;
}
