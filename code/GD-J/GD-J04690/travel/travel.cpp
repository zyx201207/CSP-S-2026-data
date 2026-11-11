#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,b1;
    string a2,b2;
    cin >> a1 >> a2>>b1>>b2;
    char c1 = a2[2];
    char c2 = b2[2];
    if(a1==b1)
    {
        cout << 1;
        if(a2[0]==b2[0]&&a2[1]==b2[1])
        {
            cout << 111;
        }
        else
        {
            cout <<"000";
        }
    }
    else
    {
        cout << "0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
