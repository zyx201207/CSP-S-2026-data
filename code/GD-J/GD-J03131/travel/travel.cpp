#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int a[10005],b[10005];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    int len=s1.size();
    if(a[0]==b[0]&&a[1]==b[1])
    {
        cout<<1;
    }
    else
        cout<<0;
    for(int i=0;i<len-1;i++)
    {

        if((a[2]=='A'&&b[2]=='B')||(b[2]=='A'&&a[2]=='B')||(a[2]=='B'&&b[2]=='C')||(b[2]=='B'&&a[2]=='C')||(b[2]=='A'&&a[2]=='C')||(a[2]=='A'&&b[2]=='C')||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D'))
        {
            cout<<1;
            break;
        }
        else
            cout<<0;
            break;
    }
    for(int i=0;i<len-1;i++)
    {
        if((a[2]=='A'&&b[2]=='B')||(b[2]=='A'&&a[2]=='B')||(a[2]=='B'&&b[2]=='C')||(b[2]=='B'&&a[2]=='C')||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D'))
        {
            cout<<1;
            break;
        }
        else{
            cout<<0;
            return 0;
        }
    }
    return 0;
}


