#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m,ans,a[1000010],b[1000010],s[1000010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    a[0]=a[1];
    for(int i=2;i<=n;i++)
    {
        b[i]=a[i]-a[i-1];
        s[i]=b[i]*(i-1)+s[i-1];
    }
    for(int i=2,j=0;i<=n;i++)
    {
        while(s[i]-s[j]-((long long)(j)*(a[i]-a[j]))>m)
            j++;
        ans=max(ans,1ll*i-j);
    }
    cout<<ans;
    return 0;
}
