#include<iostream>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int f,g,c;
	cin>>f>>g>>c;
	for(int i=1;i<=g;i++)
	{
		cout<<(g+8)%c<<endl;
	}
	return 0;
}
