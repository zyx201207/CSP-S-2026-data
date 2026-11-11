#include <iostream>
#include <string>
using namespace std;

long long a[100010];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int cnt=3;
	while(m==0)
	{
			cnt++;
			m-=cnt;		
	}
	cout << cnt;
	return 0;
}
