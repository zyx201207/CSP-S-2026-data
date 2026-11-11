#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a[8],b[8];
bool flag1 = false,flag2 = false;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2)
	{
		cout << "0000";
		return 0;
	}
    for(int i = 0;i <= 2;i++)
    {
        if(c1[i]  == c2[i])
            flag1 = true;
        else
            flag1 = false;
        a[i+1] = s1[i];
        b[i+1] = s2[i];
    }
    cout << flag1;
	if(a[1] == b[1] && a[2] == b[2])
	{
		flag2 = true;
	}
	else
	{
		cout << "000";
		return 0;
	}
	cout << flag2;
	flag2 = false;
	if(((a[3] == 'A' || a[3] == 'B' || a[3] == 'C') && (b[3] == 'A' || b[3] == 'B' || b[3] == 'C')) || ((a[3] == 'E' || a[3] == 'D') && (b[3] == 'E' || b[3] == 'D')))
		flag2 = true;
	else
	{
		cout << "00";
		return 0;
	}
	cout << flag2;
	flag2 = false;
	if(a[3] == b[3]-1 || a[3] == b[3]+1)
		flag2 = true;
	cout << flag2;
	flag2 = false;
    return 0;
}
