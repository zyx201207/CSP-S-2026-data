#include <iostream>
using namespace std;
long long a[500010],t[500010];
int n;
unsigned long long m,sum=0,mx=-1;

void gb(int st,int en)
{
    if(st==en)
    {
        return;
    }
    int mid=(en+st)/2;
    gb(st,mid);
    gb(mid+1,en);
    int i=st,j=mid+1,k=i;
    while(i<=mid&&j<=en)
    {
        if(a[i]>=a[j])
        {
            t[k]=a[j];
            k++,j++;
        }
        else if(a[i]<a[j])
        {
            t[k]=a[i];
            k++,i++;
        }
    }
    while(i<=mid)
    {
        t[k]=a[i];
        k++,i++;
    }
    while(j<=en)
    {
        t[k]=a[j];
        k++,j++;
    }
    for(int i=st;i<=en;i++)
    {
        a[i]=t[i];
    }
}

int main()
{

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    gb(1,n);
    int l=1;
    for(int i=2;i<=n;i++)
    {
        sum+=(a[i]-a[i-1])*(i-1);
        l++;
        if(sum>=m)
        {
            break;
        }
    }
    mx=l;
    long long he=1,ta=l;
    while(1)
    {
        if(ta==n)
        {
            break;
        }
        ta++;
        sum+=(a[ta]-a[ta-1])*(ta-he);
        while(sum>m)
        {
            sum-=a[ta]-a[he];
            he++;
        }
        if(ta-he+1>mx)
        {
            mx=ta-he+1;
        }
    }
    cout<<mx;

    return 0;
}
