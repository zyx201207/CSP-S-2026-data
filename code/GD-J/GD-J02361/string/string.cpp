#include <iostream>
using namespace std;
string huiwen1,huiwen2 = "";
int n;
int cnt;

int main()
{
	//freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);

	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int shul;
		char abc;
		cin >> shul >> abc;
		for(int j = 1;j <= shul;j++)
		{
			huiwen1 += abc;
		}
	}
	
	for(int i = huiwen1.size();i >= 1;i--)
	{
		huiwen2 += huiwen1[i];
	}
	
	if(huiwen1 == huiwen2) cout << 0;
	
	
	return 0;
}
