#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2;
    char s11,s12,s13;
    char s21,s22,s23;
    cin>>c1>>s11>>s12>>s13>>c2>>s21>>s22>>s23;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(c1==c2&&s11==s21&&s12==s22)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(c1==c2&&s11==s21&&s12==s22&&(((s13=='A'||s13=='B'||s13=='C')&&(s23=='A'||s23=='B'||s23=='C'))||((s13=='D'||s13=='F')&&(s23=='D'||s23=='F'))))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(c1==c2&&s11==s21&&s12==s22&&(((s13=='A'||s13=='B'||s13=='C')&&(s23=='A'||s23=='B'||s23=='C'))||((s13=='D'||s13=='F')&&(s23=='D'||s23=='F'))))
    {
        if(((s13=='D'||s13=='F')&&(s23=='D'||s23=='F')))
        {
            cout<<1;
        }
        else
        {
            if(abs(int(s13)-int(s23))==1)
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }
        }
    }
    else
    {
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
