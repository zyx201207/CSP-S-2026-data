#include<bits/stdc++.h>
using namespace std;
long long n,m,f[1000005],c,t,s[1000005],a[1000005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<n;i++)
        {
            long long a,b;
            cin>>a>>b;
            f[b]=a;
            s[a]++;
        }
        a[n]=1;
        long long x=n;
        while(x!=1)
        {
            a[f[x]]=a[x]+1;
            x=f[x];
        }
        long long l=a[1];
        for(int i=2;i<n>;i++)
        {
            if(a[i]==0)
                a[i]=a[f[i]]+1;
            if(a[i]>l)
                l=a[i];
        }
        l=l-k+2;
        l=(l+1)/2;
        l=(l-1)/2;
        cout<<l<<endl;
    }
    
    return 0;
}