#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
	  int n,k;
	  cin>>n>>k;
	  for(int i=1;i<n;i++)
	  {
	    int u,v;
	    cin>>u>>v;
	    //add(u,v);add(v,u);
	  }
	  cout<<rand()%(n/2);
	}
	return 0;
}

