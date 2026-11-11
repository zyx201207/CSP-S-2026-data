#include<bits/stdc++.h>
using namespace std;

int n = 2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;

    cin >> c1 >> s1 >> c2 >> s2;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(c1[j-i] == c2[j-i])
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
            if(s1[j-i] == s2[j-i])
            {
                cout << "1";
            }

            else
            {
                cout << "0";
            }

        }
        return 0;
    }

    return 0;
}
