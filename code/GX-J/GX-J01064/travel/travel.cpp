#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out", "w", stdout);

    string s1,s2,c1,c2,p1,p2;
    char q1,q2;
    cin>>s1>>c1>>s2>>c2;
    for(int i=0;i<2;i++)
    {
        p1+=c1[i];
        p2+=c2[i];
    }
    q1=c1[2];
    q2=c2[2];

    if(s1==s2)
        cout<<1;
    else cout<<0;

    if(s1==s2 && p1==p2)
        cout<<1;
    else cout<<0;

    if(s1==s2 && p1==p2)
    {
        if(q1<='C' && q2<='C' || q1>'C' && q2>'C')
            cout<<1;
        else cout<<0;
    }
    else cout<<0;


    if(s1==s2 && p1==p2)
    {
        if(q1<='C' && q2<='C' || q1>'C' && q2>'C')
        {
            if(q2>q1)
                swap(q1,q2);
            if(q1-q2==1)
                cout<<1;
            else cout<<0;
        }
        else cout<<0;
    }
    else cout<<0;

    return 0;
}
