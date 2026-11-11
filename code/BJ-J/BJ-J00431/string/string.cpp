#include<bits/stdc++.h>
using namespace std;
int n,a[2100000];
long long ans=0;
char b[2000000];
int main()
{
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
            if(a[l]==a[r])
            {
                l++;
                r--;
            }
            else if(a[l]>a[r])
            {
                a[l]-=a[r];
                r--;
            }
            else
            {
                a[r]-=a[l];
                l++;
            }
        }
        else
        {
            if(a[l]==a[r])
            {
                l++;
                r--;
                ans+=a[l];
            }
            else if(a[l]>a[r])
            {
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
            else
            {
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
