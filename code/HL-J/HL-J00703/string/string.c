#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,num=0;
    string sum;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        for(int j=1;j<=a;j++)
        {
            int b;
            cin>>b;
            sum+=b;
        }
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(sum[i]£¡=sum[n-i-1])
        {
            sum[n-i-1]=sum[i];
            num++;
        }
    }
    cout<<num;
    return 0;
}
