#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,s1,s2,s3;
    cin>>s>>s1>>s2>>s3;
    int f = 1,f1 = 1,f2 = 1;
    if(s == s2)cout<<"1";
    else
    {
        f = 0;
        cout<<"0";
    }
    if(f == 1&&s1[0] == s3[0]&&s1[1] == s3[1])cout<<"1";
    else
    {
        f1 = 0;
        cout<<"0";
    }
    if(f1 == 1&&((s1[2]<='C')&&(s3[2]<='C'))||((s1[2]>='D')&&(s3[2]>='D')))cout<<"1";
    else
    {
        f2 = 0;
        cout<<"0";
    }
    if(f2 == 1&&((s1[2]+1) == s3[2]||s1[2] == (s3[2]+1)))cout<<"1";
    else cout<<"0";
    return 0;
}
