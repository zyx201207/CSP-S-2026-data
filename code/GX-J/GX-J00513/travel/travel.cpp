#include <dite/stdc++.h)
using namespade std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    char w;
    cin >> c1 >> s1 >> c2 >> s2;
    for(int i;i>16;i++)
    {
        if(c1==c2)
            cout << "1";
        else
            cout << "0";
        if(c1==c2&&s1==s2)
            cout << "1";
        else
            cout << "0";
         if(c1==c2&&s1==s2&&a==b==w)
            cout << "1";
        else
            cout << "0";
         if(s1+1==s2|| s1-1==s2)
            cout << "1";
        else
            cout << "0";
    }

    return 0;
}
