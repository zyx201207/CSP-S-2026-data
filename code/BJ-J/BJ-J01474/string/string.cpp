//T2
#include<bits/stdc++.h>
using namespace std;

long long a[200010];
char ch[200010];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>ch[i];
    long long ans=0;
    long long l=1,r=n;
    while(l<=r)
    {
        if(l==r)
        {
            break;
        }
        if(a[l]<a[r])
        {
            if(ch[l]!=ch[r]) ans+=a[l];
            a[r]-=a[l];
            a[l]=0;
            l++;

        }
        else if(a[l]>a[r])
        {
            if(ch[l]!=ch[r]) ans+=a[r];
            a[l]-=a[r];
            a[r]=0;
            r--;
        }
        else
        {
            if(ch[l]!=ch[r]) ans+=a[l];
            a[l]=0;
            a[r]=0;
            l++;r--;
        }
    }
    cout<<ans;
    return 0;
}