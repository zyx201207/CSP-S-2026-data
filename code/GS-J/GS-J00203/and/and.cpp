#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen(travel.in,'r',stdion);
    freopen(travel.out,'r',stdion);
    string a,b;
    int x,r;
    int len=a.size();
    cin>>x>>a>>r>>b;
    for(int i=0;i<=len;i++)
    {
        if(x==r)
        {
            cout<<'1';
        }
        else
        {
            cout<<'0';
        }
        if(x==r&&a[0]==b[0]&&a[1]==b[1])
        {
            cout<<'1';
        }
        else
        {
            cout<<'0';
        }
        if(x==r&&a[0]==b[0]&&a[1]==b[1]&&a[2]+1==b[2]&&a[2]+1!='D')
        {
            cout<<'1';
        }
       else  if(x==r&&a[0]==b[0]&&a[1]==b[1]&&a[2]+2==b[2]&&a[2]+2!='D'&&a[2]+2!='F')
           {
               cout<<'1';
           }
           else if(x==r&&a[0]==b[0]&&a[1]==b[1]&&b[2]+1==a[2]&&b[2]+1!='D')
           {
               cout<<'1';
           }
           else if(x==r&&a[0]==b[0]&&a[1]==b[1]&&b[2]+2==a[2]&&b[2]+2!='D'&&b[2]+2!='F')
           {
               cout<<'1';
           }
        else
        {
            cout<<'0';
        }
        if(x==r&&a[0]==b[0]&&a[1]==b[1]&&a[2]+1==b[2]&&a[2]+1!='D')
           {
               cout<<'1';
           }
           else
           {
               cout<<'0';
           }
    }
    return 0;
}
