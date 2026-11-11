#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string c1;
string c2;
string s1;
string s2;
int a[4];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;

    int i[100];
    if(c1==c2)
    {
        a[0]=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            a[1]=1;
            if((s1[2]<='c'&&s2[2]<='c')||(s1[2]>'c'&&s2[2]>'c'))
            {
                a[2]=1;
                if(s2[2]-s1[2]==1||s2[2]-s1[2]==-1)
                    a[3]=1;

            }

        }

    }

    cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0;
}
