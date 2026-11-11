#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[200005];
char c[200005];
ll ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d %c",&a[i],&c[i]);
    int i=1,j=n;
    while(i<j)
    {
        if(a[i]>a[j])
        {
            if(c[i]!=c[j]) ans+=a[j];
            a[i]-=a[j],a[j]=0;
            j--;
        }
        else if(a[i]<a[j])
        {
            if(c[i]!=c[j]) ans+=a[i];
            a[j]-=a[i];
            a[i]=0;
            i++;
        }
        else
        {
            if(c[i]!=c[j]) ans+=a[i];
            a[i]=a[j]=0;
            i++,j--;
        }
    }cout<<ans;
    return 0;
}