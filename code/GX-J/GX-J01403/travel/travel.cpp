#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	int n=int(x[2]),m=int(y[2]);
	if(a==b)
	{
		cout<<"1";
		if(x[0]==y[0]&&x[1]==y[1])
		{
			cout<<"1";
			if((n>=68&&m>=68)||(n<68&&m<68))
			{
				cout<<"1";
				if(n-m==1||m-n==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
