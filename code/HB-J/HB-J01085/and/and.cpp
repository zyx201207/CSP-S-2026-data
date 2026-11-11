#include <bits/stdc++.h>

using namespace std;
long long n,a[200005],ans,m,sum,f[200005],num,flag;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=a[i];

    }
    sort(a+1,a+1+n);
    sum=n;
    for(int i=30;i>=0;i--){

        memset(f,0,sizeof(f));
        num=0;
        for(int j=sum;j>=1;j--)
        {
            if(a[j]&(1<<i)!=0)
            {
                num++;
                f[num]=a[j];
            }
        }
        if(num<m){
            if(flag==1)
            {
                ans=a[sum];
                for(int i=sum-1;i>=sum-m+1;i--)ans=ans&a[i];
                break;
            }
        }
        else flag=1;
        sum=num;
        for(int i=1;i<=num;i++)
        {
            a[num-i+1]=f[i];
        }
     }
    cout<<ans;
    return 0;
}
