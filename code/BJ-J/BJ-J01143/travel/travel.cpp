#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long n,m;
    char a[3],b[3];
    cin >> n;
    for(int i=0;i<3;i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for(int i=0;i<3;i++)
    {
        cin >> b[i];
    }
    if (n == m)
    {
        cout << 1;
    if (a[0]==b[0]&&a[1]==b[1])
    {
        cout << 1;
    }else{
        cout << 0;
    }
    if (a[0]==b[0]&&a[1]==b[1])
   {
       if(((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F'))||((a[2]!='D'&&a[2]!='F')&&(b[2]!='D'&&b[2]!='F')))
       {
           cout << 1;
       }else{
           cout << 0;
       }
    }else{
    cout << 0;
    }
    if (a[0]==b[0]&&a[1]==b[1])
    {
        if((a[2]=='D'||a[2]=='F')&&(b[2]=='D'||b[2]=='F'))
        {
             cout << 1;
        }else if(((a[2]!='D'||a[2]!='F')&&(b[2]!='D'||b[2]!='F'))&&(a[2]=='B'||b[2]=='B'))
        {
                 cout << 1;
        }else{
             cout << 0;
        }
    }else{
       cout << 0;
    }
    }else{
        cout << 0 << 0 << 0 << 0;
    }
    return 0;
}
