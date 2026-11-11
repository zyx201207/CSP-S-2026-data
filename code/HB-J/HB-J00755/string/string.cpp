
#include <iostream>
using namespace std;
int main()
{
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
	int n,a;
	long long s=1,lop=0;
	char b;
	string c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		while(a)
		{
			c[s++]=b;
			a--;
		}
	}
	for(int i=1,j=s-1;i<=j;i++,j--)
	{
		if(c[i]!=c[j])
		{
			lop++;
		}
	}
	cout<<lop;
	return 0;
}

