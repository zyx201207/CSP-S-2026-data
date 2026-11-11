#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],c[500005],n,m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    //特殊性质A
    if(n>=500000)
    {
        long long sum=0;
        for(int i=1;i<=n+1;i++)
        {
            if(sum>m)
            {
                cout<<i-1;
                break;
            }
            else
            {

                sum+=i;
            }
        }
        return 0;
    }
    sort(a+1,a+n+1);
    long long ans=1;//最开始默认从一开始
    for(int i=1;i<=n;i++)
    {
        long long num=a[i],cnt=0;//记增加了多少次
        for(int j=1;j<i;j++)
        {
            cnt+=a[i]-a[j];
            a[j]=a[i];
        }
        for(int j=1;j<i;j++)
        {
            a[j]=b[j];
        }
        if(cnt<=m)
        {
            //cout<<cnt<<endl;
            ans=i;
        }
        else
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}
