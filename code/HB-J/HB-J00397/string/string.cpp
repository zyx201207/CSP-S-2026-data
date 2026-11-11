#include <iostream>
using namespace std;
long long n,s=0;
string a,ans;
int main()
{
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long u;
		char v;
		cin>>u>>v;
		for(long long j=1;j<=u;j++)
		{
			a+=v;
		}
	}
	for(long long i=0,j=a.size()-1;i<=j;i++,j--)
	{
		if(a[i]!=a[j])
		{
			a[j]=a[i];
			s++;
		}
	}
	cout<<s;
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
 
 
*/
