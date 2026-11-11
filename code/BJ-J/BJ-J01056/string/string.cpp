#include<iostream>
#include<cstdio>
using namespace std;
long long n;
long long lll=0,l=1,r,cnt=0;
struct node{
    long long num;
    char s;
}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i].num>>a[i].s;
        lll+=a[i].num;
    }
    r=n;
    while(l<r)
    {
        if(a[l].num<a[r].num)
        {
            if(a[l].s!=a[r].s)
            {
                cnt+=a[l].num;
            }
            l++;
            a[r].num-=a[l].num;
        }
        else if(a[l].num>a[r].num)
        {
            if(a[l].s!=a[r].s)
            {
                cnt+=a[r].num;
            }
            r--;
            a[l].num-=a[r].num;
        }
        else
        {
            if(a[l].s!=a[r].s)
            {
                cnt+=a[r].num;
            }
            l++;
            r--;
        }
    }
    cout<<cnt;
    return 0;
}