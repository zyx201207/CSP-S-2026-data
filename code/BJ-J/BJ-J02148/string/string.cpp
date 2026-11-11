#include<bits/stdc++.h>
using namespace std;
int a[100005];
char c[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s1,s2;
    int n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            string=string+c[i];
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=a[i];j++)
        {
            string=string+c[i];
        }
    }
    if(s1==s2)
    {
        cout<<"0";
        return 0;
    }
    return 0;
}
