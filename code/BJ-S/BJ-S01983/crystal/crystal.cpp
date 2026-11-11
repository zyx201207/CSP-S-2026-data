#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010],c[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    bool sp1=true,sp2=true;
    int cha=a[2]-a[1];
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=i) sp1=false;
        if(i!=2&&i!=1&&a[i]-a[i-1]!=cha) sp2=false;
        if(!sp1&&!sp2) break;
    }
    if(sp1)
    {
        for(int i=1;i<=n;i++)
            if((1+i)*i/2>m)
            {
                cout<<i<<endl;
                return 0;
            }
        cout<<n<<endl;
        return 0;
    }
    if(sp2)
    {
        for(int i=1;i<=n;i++)
            if((1+i)*i/2*cha>m)
            {
                cout<<i<<endl;
                return 0;
            }
        cout<<n<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
        b[i]=a[i+1]-a[i];
    for(int i=1;i<n;i++)
    {
        a[i]=a[i-1]+a[i];
        c[i]=c[i-1]+i*b[i];
    } 
    long long l=1,r=0;
    long long ans=0;
    while(r<n&&l<=r+1)
    {
        //cout<<l<<" "<<r<<" "<<c[r]-c[l-1]-(l-1)*(a[r]-a[l-1])<<endl;
        if(c[r]-c[l-1]-(l-1)*(a[r]-a[l-1])>m) l++,r=max(r,l);
        else
        {
            r++;
            //cout<<l<<" "<<r<<endl;
            ans=max(ans,r-l+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}