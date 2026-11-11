#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long n;
    char m;
}a[1000100],b[1000100];
long long idx,f,sum,l,r,ans;
int check(long long x,long long y)
{
    if(x==y)return 0;
    long long l=x-y;
    if(l>0)
    {
        return 2;
    }
    return 1;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        cin>>a[i].n>>a[i].m;
        idx+=a[i].n;
    }
    long long s=idx+1;
    s/=2;
    for(int i=0;i<x;i++)
    {
        if(sum+a[i].n>s&&f==0)
        {
            f=1;
            l=i;
            r=i+1;
            if(idx%2==1)
            {
                b[i].n=s-sum-1;
                b[i].m=a[i].m;
                b[i+1].m=a[i].m;
                b[i+1].n=sum+a[i].n-s;
            }
            else
            {
                b[i].n=s-sum;
                b[i].m=a[i].m;
                b[i+1].m=a[i].m;
                b[i+1].n=sum+a[i].n-s;
            }
        }
        else b[i+f]=a[i];
        sum+=a[i].n;
    }
    while(l>=0&&r<x+1)
    {
        int las=check(b[l].n,b[r].n);
        if(b[l].m==b[r].m)
        {
            if(las==1)
            {
                b[r].n-=b[l].n;
                l--;
            }
            if(las==0)
            {
                l--;
                r++;
            }
            if(las==2)
            {
                b[l].n-=b[r].n;
                r++;
            }
        }
        else
        {
            if(las==1)
            {
                ans+=b[l].n;
                b[r].n-=b[l].n;
                l--;
            }
            if(las==0)
            {
                ans+=b[r].n;
                l--;
                r++;
            }
            if(las==2)
            {
                ans+=b[r].n;
                b[l].n-=b[r].n;
                r++;
            }
        }
    }
    cout<<ans;
    return 0;
}
