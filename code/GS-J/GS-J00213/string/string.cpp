#include<bits/stdc++.h>

using namespace std;
int n , m , num , nm = 0;
char s;
string a;

int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	while(n--)
	{
		cin >> m >> s;
		for(int i = 1; i <= m;i++)
		{
			a += s;
		}
	}
	nm = a.size();
	if(n == 1)
    {
       cout << 0;
       return 0;
    }
    for(int i = 0; i < nm/ 2; i++)
    {
        if(a[i] != a[nm-i-1])
            num++;
    }
    cout << num;
	return 0;
}

