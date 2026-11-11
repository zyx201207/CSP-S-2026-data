#include<iostream>
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int f,g,c;
	cin>>f>>g>>c;
	for(int i=1;i<=g;i++)
	{
		cout<<(g+8)%c<<endl;
	}
	return 0;
}
