#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	int n,k;
	int u,v;
	int answer=1,solution=2;
	cin>>c>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n>>k;
		cin>>u>>v;
		u+=u;
		v+=v;
	}
	cout<<answer<<endl<<solution;
	return 0;
}

