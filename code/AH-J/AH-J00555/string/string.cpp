#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,num,sum = 0;
	cin >> n;
	string a = "",b;
	for(int i = 1;i<=n;i++)
    {
        cin >> num >> b;
        string s = num * b;
        a += s;
    }
    for (int i = 0;i<lenth(a);i++)
    {
        for (int j = lenth(a);j>=0;j--)
        {
            if (a[i] != a[j])
            {
                sum++;
            }
        }
    }
    cout << sum;
	return 0;
}
