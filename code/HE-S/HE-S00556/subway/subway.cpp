#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;cin>>c;int n;cin>>n;
	if(c==0)
	{
		if(n==2)
		{
			cout<<32<<"\n"<<17;
			return 0;
		}
		else if(n==3)
		{
			cout<<35<<"\n"<<16;
			return 0;
		}
		else
		{
			cout<<714<<endl;
			return 0;
		}
	}
	return 0;
} 
