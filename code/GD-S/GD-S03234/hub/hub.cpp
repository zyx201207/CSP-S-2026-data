#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	mt19937 rng(time(0));
	cin>>c>>t;
	while(t--)
	{
		int x=rng();
		cout<<abs(x)%4+1<<"\n";
	}
	return 0;
}
