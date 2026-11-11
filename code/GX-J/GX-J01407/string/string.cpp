#include<bits/stdc++.h>
using namespace std;
struct po
{
    long long n;
    char c;
}a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].n>>a[i].c;
    }
    long long l=1,r=n;
    long long sum=0;
    while(l!=r)
    {
        if(l+1==r)
        {
            if(a[l].c!=a[r].c)
            {
                sum+=min(a[r].n,a[l].n);
                break;
            }
            else
            {
                break;
            }
        }
        if(a[l].c!=a[r].c)
        {
            if(a[l].n>a[r].n)
            {
                sum+=a[r].n;
                a[l].n-=a[r].n;
                r--;
            }
            else if(a[l].n<a[r].n)
            {
                sum+=a[l].n;
                a[r].n-=a[l].n;
                l++;
            }
            else
            {
                sum+=a[l].n;
                l++;
                r--;
            }
        }
        else
        {
            if(a[l].n>a[r].n)
            {
                a[l].n-=a[r].n;
                r--;
            }
            else if(a[l].n<a[r].n)
            {
                a[r].n-=a[l].n;
                l++;
            }
            else
            {
                l++;
                r--;
            }
        }
    }
    cout<<sum;
    return 0;
}
