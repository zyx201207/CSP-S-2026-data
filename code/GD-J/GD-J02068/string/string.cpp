#include <iostream>
using namespace std;
int k[11];
char p[11];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{cin>>k[i]>>p[i];
	}
	if(p[1]==p[n]&&p[2]==p[n-1])cout<<0;
	else if(p[1]!=p[n]&&p[2]==p[n-1])cout<<1;
	else if(p[1]!=p[n]&&p[2]!=p[n-1])cout<<2;
	return 0;
}
