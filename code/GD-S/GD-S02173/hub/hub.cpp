#include<bits/stdc++.h>
using namespace std;
struct hub{
	int one;
	int two;
};
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int o=0;o<t;o++)
	{
		int n,m;
		cin>>n>>m;
		hub a[n-1];
		for(int i=0;i<n-1;i++)
		{
			cin>>a[i].one>>a[i].two;
		}
		cout<<m-1<<endl;
	}
	return 0;
}
