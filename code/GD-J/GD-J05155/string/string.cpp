#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a[1000010];
	int n,m,l;
	char h;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>h;
		l+=m;
	}
	cout<<l/2; 
	return 0;
 } 
