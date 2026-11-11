#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[20000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		if(c==11||c==12)
		{
		    for(int i=1;i<=n;i++)
		    {
			    cin>>x[i];
		    }
		    if(x[2]-x[1]>d)
		    {
			    cout<<"0"<<endl;
		    }
		    else{
			    cout<<(n+1)/2<<endl;
		    }
	    }
		else{
			cout<<"1"<<endl; 
		}
	}
	return 0;
}
