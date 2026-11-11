#include <iostream>
#include <string>
using namespace std;
int a,m,y;
char p;
string n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for (int i=0;i<a;i++)
	{
		cin>>m;
		cin>>p;
		n+=p*m;
		p+=m;
	}
	int h=0,q=p-1,d=0;
	while (q>d)
	{
		if (n[d]!=n[q])
		{
			h++;
		}
		d++;
		q--;
	}
	cout<<h;
}
