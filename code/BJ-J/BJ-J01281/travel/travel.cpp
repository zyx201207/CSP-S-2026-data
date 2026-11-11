#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
int main()
{
    freopen('travel.in','r',stdin);
    freopen('travel.out','w',stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    if(c1=c2)
    {
        cout << '1111';
    }
    else
    {
        cout << '0000';
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
