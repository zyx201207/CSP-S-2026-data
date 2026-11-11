#include <iostream>
using namespace std;
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	string hui;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		int x1;
		string x2;
		cin >> x1 >> x2;
		for (int i=1;i<=x1;i++)
		{
			hui+=x2;
		}
	}
	return 0;
}
