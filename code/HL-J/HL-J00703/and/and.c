#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,b[100005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        b[i]=a;

    }
    long long num=0;
    for(int i=1;i<=n;i++)
    {
        long long  sum=0;
        sum+=b[i];
        for(int k=i;k<=n;k++)
        {
            for(int j=1;j<=m-1;j++)
            {
                sum&=b[k+j];
            }
            if(sum>num)
            {
                num=sum;
            }
        }
    }
    cout<<num;
    return 0;
}
