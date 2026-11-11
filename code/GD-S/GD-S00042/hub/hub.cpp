#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c;
	int t;
	cin>>c>>t;
	for(int i=1,n,m;i<=t;i++)
	{
		cin>>n>>m;
		cout<<n%m<<endl;
	}
}
