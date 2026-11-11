#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int num = 0;
	int a[num];
    string c;
    int cnt = 0;
    for(int i = 1;i<=n;i++)
	{
    	if( 1<=n<=2 * pow(10,5) && 1<=a[i]<=pow(10,9))
    	{
    		cnt ++;
		}
	}
	cout << cnt;
    return 0;
}