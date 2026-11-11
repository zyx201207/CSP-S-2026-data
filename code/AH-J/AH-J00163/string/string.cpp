#include <bits/stdc++.h>
using namespace std;
int main()
{
    sizeof("string.in","r",stdin);
    sizeof("string.out","w",stdout);
    long long n,a[200005],st=0;
    string b[200005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    int l=1,r=n;
    while(l<r)
    {
        if(b[l]==b[r])
        {
            if(a[l]>a[r])
            {
                a[l]-=a[r];
                a[r]=0;
                r--;
            }
            else if(a[l]<a[r])
            {
                a[r]-=a[l];
                a[l]=0;
                l++;
            }
            else
            {
                a[l]=0;
                a[r]=0;
                l++;
                r--;
            }
        }
        else
        {
            if(a[l]>a[r])
            {
                st+=a[r];
                a[l]-=a[r];
                a[r]=0;
                r--;
            }
            else if(a[l]<a[r])
            {
                st+=a[l];
                a[r]-=a[l];
                a[l]=0;
                l++;
            }
            else
            {
                st+=a[r];
                a[l]=0;
                a[r]=0;
                l++;
                r--;
            }
        }
    }
    cout<<st;
    return 0;
}

