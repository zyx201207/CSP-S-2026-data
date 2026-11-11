#include<bits/stdc++.h>
using namespace std;
struct stu
{
    long long num;
    char b;
}a[200005];
long long ans=0,sum=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,t=0,i=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num>>a[i].b;
    }
    t=n;
    i==1;
    while(i<=t)
    {
        if(a[i].num>=a[t].num)
        {
            if(a[i].b!=a[t].b)
            {
                ans+=a[t].num;
                a[i].num-=a[t].num;
            }
            if(a[i].b==a[t].b)
            {
                a[i].num-=a[t].num;
            }
            t--;
        }
        if(a[i].num<=a[t].num)
        {
            if(a[i].b!=a[t].b)
            {
                ans+=a[i].num;
                a[t].num-=a[i].num;
            }
            if(a[i].b==a[t].b)
            {
                a[t].num-=a[i].num;
            }
            i++;
        }
    }
    cout<<ans;
    return 0;
}
