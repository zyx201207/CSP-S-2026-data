#include <iostream>
using namespace std;
string q3[]={"AB","AC","BC","DF"},q4[]={"AB","BC","DF"};
int main()
{
	ios::sync_with_stdio(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2,f;
	char p1,p2;
	cin>>c1>>s1>>p1>>c2>>s2>>p2;
	cout<<(c1==c2);
	cout<<(c1==c2&&s1==s2);
	f=0;
	for (int i=0;i<=3;++i)
		if ((p1==q3[i][0]&&p2==q3[i][1])||(p1==q3[i][1]&&p2==q3[i][0]))
			{
				f=1;
				break;
			}
	cout<<(c1==c2&&s1==s2&&f);
	f=0;
	for (int i=0;i<=2;++i)
		if ((p1==q4[i][0]&&p2==q4[i][1])||(p1==q4[i][1]&&p2==q4[i][0]))
			{
				f=1;
				break;
			}
	cout<<(c1==c2&&s1==s2&&f);
	return 0;
}
