#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int l=1,r=n,ls=a[1],rs=a[n];
    long long sum=0,cnt=0;
    while(l<r)
    {
        cnt++;
        if(c[l]!=c[r])
        {
            sum+=min(ls,rs);
        }
        if(ls<rs)
        {
            rs-=ls;
            l++;
            ls=a[l];
        }
        else if(ls==rs)
        {
            l++;
            r--;
            ls=a[l];
            rs=a[r];
        }
        else
        {
            ls-=rs;
            r--;
            rs=a[r];
        }
    }cout<<sum;
    return 0;
}

