#include<bits/stdc++.h>
using namespace std;
string s[100000];
string k[100000];
int a[10000],c[10000];
int main()
{
    freopen("travel.in";"r".stdin)
    freopen("travel.out";"w".stdout)

    int n,sum=1;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=sum;j<=a[i];j++)
        {
            s[j]=c[i];
            sum=a[i];
            a[i]+=a[i+1];
        }
    }
    sum=1;
    for(int i=n;i>=1;i--)
    {
        a[i]+=a[i-1];
        for(int j=a[i];j>=sum;j--)
    }














    return 0;
}
