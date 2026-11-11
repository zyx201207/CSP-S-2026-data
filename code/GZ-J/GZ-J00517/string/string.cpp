//GZ-J00517，石浩辰 ，北京师范大学贵阳附属中学 
#include <iostream>
using namespace std;
int n , a[100002] , f;
char b[100002];
bool e = 1;
void c()
{
	for (int i = 1 ; i <= n ; i++)
	{
		if (a[i] != a[1 + n - i] || b[i] != b[1 + n - i])
		{
			e = 0;
			break;
		}
	}
}
int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout); 
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i] >> b[i]; 
	}
	c();
	if (e)  
	{
		cout << '0';
		return 0;
	}
	else
	{
		for (int i = 1 ; i <= n ; i++)
		{
			f += a[i];
		}
		if (f % 2 == 1)
	}
	return 0;
} 
