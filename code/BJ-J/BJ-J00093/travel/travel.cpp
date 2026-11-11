#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
string str1,str2,str3,str4;
char e,f;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> str1 >> str2 >> str3 >> str4;
    for(int i = 0;i < str1.length();i++) a = a * 10 + str1[i] - '0';
    for(int i = 0;i < str3.length();i++) c = c * 10 + str3[i] - '0';
    for(int i = 0;i < str2.length() - 1;i++) b = b * 10 + str2[i] - '0';
    for(int i = 0;i < str4.length() - 1;i++) d = d * 10 + str4[i] - '0';
    e = str2[str2.length() - 1];
    f = str4[str4.length() - 1];
    if(a == c)
    {
        cout << 1;
        if(b == d)
        {
            cout << 1;
            if(('A' <= e && e <= 'C' && 'A' <= f && f <= 'C') || ((e == 'D' || e == 'F') && (f == 'D' || f == 'F')))
            {
                cout << 1;
                if(abs((int)(f - e)) == 1 || (e == 'D' && f == 'F') || (e == 'F' && f == 'D')) cout << 1;
                else cout << 0;
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
