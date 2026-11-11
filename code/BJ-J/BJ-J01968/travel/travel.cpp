#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 == c2)
    {
        cout <<"1";
    }
    if(c1 != c2)
    {
        cout << "0";
    }
    string p1 = "",p2 = "";
    for(int i = 0;i<s1.length();i++)
    {
        if(s1[i]>='0'&&s1[i]<='9')
        {
            p1+=s1[i];
        }
    }
    for(int i = 0;i<s2.length();i++)
    {
        if(s2[i]>='0'&&s2[i]<='9')
        {
            p2+=s2[i];
        }
    }
    if(c1 == c2&&p1 == p2)
    {
        cout << "1";
    }
    else
    {
        cout <<"0";
    }

    string n1 = "",n2 = "";
    for(int i = 0;i<s1.length();i++)
    {
        if(s1[i]>='A'&&s1[i]<='Z')
        {
            n1+=s1[i];
        }
    }
    for(int i = 0;i<s2.length();i++)
    {

        if(s2[i]>='A'&&s2[i]<='Z')
        {
            n2+=s2[i];
        }
    }
    if(c1 == c2&&p1 == p2&&((n1<"C"&&n2<"C")||(n1>"C"&&n2>"C")||(n1<"D"&&n2<"D")))
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }

    char a1,a2;
    for(int i = 0;i<s1.length();i++)
    {
        if(s1[i]>='A'&&s1[i]<='Z')
        {
            a1 = s1[i];
            break;
        }
    }
    for(int i = 0;i<s2.length();i++)
    {
        if(s2[i]>='A'&&s2[i]<='Z')
        {
            a2 = s2[i];
            break;
        }
    }
    if((a1 == 'C'&&a2 == 'D')||(a1 == 'D'&&a2 == 'C'))
    {
        cout << "0";
        return 0;
    }
    if(c1 == c2&&p1 == p2&&a1>a2&&a1-a2 == 1)
    {
        cout << "1";
    }
    else if(c1 == c2&&p1 == p2&&a1<a2&&a2-a1==1)
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
    return 0;
}
