#include<bits/stdc++.h>
using namespace std;
string s1={};
long long n,m;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
//int a=1000000000;
//string b="a";
//    for(long long  j=1;j<=a;j++)
//        {
//            s1+=b;
//        }
    for(long long  i=1;i<=n;i++)
    {
        int a;
        string b;
        cin>>a>>b;
        for(long long  j=1;j<=a;j++)
        {
            s1+=b;
        }
        m+=a;
    }
    long long bj=0;
    for(long long  i=0,j=m-1;i<=j;i++,j--)
    {
        if(s1[i]!=s1[j])
        {
            bj++;
        }
    }
    cout <<bj;
    return 0;
}
