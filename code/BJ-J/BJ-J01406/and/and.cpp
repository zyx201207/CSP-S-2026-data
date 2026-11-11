#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
    return a>b;
}
int n,m;
long long a[200005];
long long num,sum;
int j;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    j=1;
    do
    {
        sum=a[j];
        for(int i=j+1;i<=j+m-1;i++)
        {
            sum=sum&a[i];
            if(sum==0)
            {
                j=i;
                break;
            }
        }
    }while(sum==0);
    cout<<sum;
    return 0;
}
