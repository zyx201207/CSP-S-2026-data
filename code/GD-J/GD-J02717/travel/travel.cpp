#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1=1;
    int a2=1;
    int a3=1;
    int a4=1;
    string c1;
    string s1;
    string c2;
    string s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        a1=0;
        a2=0;
        a3=0;
        a4=0;
    }
    cout<<a1<<a2<<a3<<a4;
    return 0;
}
