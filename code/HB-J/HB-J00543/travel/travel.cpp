#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int a[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)
    {
        a[1] = 1;
    }
    else
    {
        cout << "0000" << endl;
        return 0;
    }
    if(s1[0] == s2[0] && s1[1] == s2[1])
    {
        a[2] = 1;
    }
    else
    {
        cout << "1000" << endl;
        return 0;
    }
    if(((s1[2] >= 'A' && s1[2] <= 'C') && (s2[2] >= 'A' && s2[2] <= 'C')) || ((s1[2] >= 'D' && s1[2] <= 'F') && (s2[2] >= 'D' && s2[2] <= 'F')))
    {
        a[3] = 1;
    }
    else
    {
        cout << "1100" << endl;
        return 0;
    }
    if(abs(s1[2] - s2[2]) == 1)
    {
		//if(!(s1[2] == 'C' && s2[2] == 'D') && !(s1[2] == 'D' && s2[2] == 'C'))
		a[4] = 1;
    }
    else
    {
		//cout << abs(s1[2] - s2[2]);
        cout << "1110" << endl;
        return 0;
    }
    for(int i=1;i<=4;i++)
    {
        cout << a[i];
    }
    return 0;
}
