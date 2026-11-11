//贵阳市观山湖区外国语实验中学林浩宇GZ-J00118 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,sum = 0;
	cin >> n;
	string b,b1;
	bool flag = true;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a >> b;
		sum += a;
		if(b1 != b && i != 1)
		{
			flag = false;
		}
		b1 = b;
	}
	if(flag)
	{
		cout << 0;
	}	
	else
	{
		cout << sum / 2;
	}
	return 0;
}
