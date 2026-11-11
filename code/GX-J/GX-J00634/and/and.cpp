#include<bits/stdc++.h>
using namespace std;
string c1,c2;
long long sum[100000000],num;
int cs,n,a,b;
long long fh,c3[100000000];
int main()
{

    freopen("and1.in","r",stdin);
    freopen("and1.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        cin>>fh;
        c3[i]=fh;
    }
    sum[1]=c3[1]&c3[2];
    for(int i=2;i<=a;i++)
    {
        for(int j=i;j<=b;j++)
        {
            sum[i]=sum[i]&c3[j];
        }
    }
    for(int i=2;i<=b;i++)
    {
        if(sum[i]>sum[i-1])
        {
            num=sum[i];
        }
    }
    cout <<num;
    return 0;
}
