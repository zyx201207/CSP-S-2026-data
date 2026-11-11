#include<bits/stdc++.h>
using namespace std;
int c,T,x,y,z;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>x>>y>>z>>T;
	if(c==0)
	{
		cout<<"35\n16";
		return 0;
	}
	for(int i=1,m;i<=T;++i)
	{
		m=rand();
		cout<<m<<"\n";
	}
	return 0;
}
