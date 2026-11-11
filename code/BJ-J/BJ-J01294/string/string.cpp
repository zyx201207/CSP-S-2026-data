#include<iostream>
using namespace std;
int n;
int a[200005];
char c[200005];
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r)
    {
        if(c[l]!=c[r])
        {
            ans+=min(a[l],a[r]);
        }
        if(a[l]>a[r])
        {
            a[l]-=a[r];
            r--;
            continue;
        }
        if(a[l]==a[r])
        {
            l++;
            r--;
            continue;
        }
        if(a[l]<a[r])
        {
            a[r]-=a[l];
            l++;
            continue;
        }
    }
    cout<<ans;
    return 0;
}