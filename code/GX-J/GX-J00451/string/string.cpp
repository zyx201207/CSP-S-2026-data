#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
string c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cin>>c[i];
    }
    long long m=(n+1)/2;
    long long ans=0;
    for(int i=1;i<m;i++)
    {
        if(c[i]!=c[m+i]){
            ans+=a[i];
        }
    }
    if(n%2==0)
    {
        if(c[m]!=c[n])
        {
            ans+=a[m];
        }
    }
    cout<<ans;
    return 0;
}
