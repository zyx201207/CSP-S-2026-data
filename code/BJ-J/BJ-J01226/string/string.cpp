#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],a2[200010];
int b[500010],len,ans;
char c[200010],c2[200010];
string s;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i],len+=a[i];
    if(len<=1e7)
    {
        s=" ";
        for(int i=1;i<=n;i++)
            for(int j=1;j<=a[i];j++)
                s+=c[i];
        for(int i=1;i<=len/2;i++)
            if(s[i]!=s[len+1-i])
                ans++;
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)
        a2[i]=a[i],c2[i]=c[i];
    reverse(a2+1,a2+1+n);
    reverse(c2+1,c2+1+n);
    for(int i=1;i<=n;i++)
    {
        a[i]+=a[i-1];
        a2[i]+=a2[i-1];
        b[i]=a[i];
        b[n+i]=a2[i];
    }
    sort(b+1,b+1+2*n);
    int k=unique(b+1,b+1+2*n)-b-1;
    for(int i=1;i<=k;i++)
    {
        int id1=lower_bound(a+1,a+1+n,b[i])-a;
        int id2=lower_bound(a2+1,a2+1+n,b[i])-a2;
//        cout<<id1<<" "<<id2<<"\n";
        if(c[id1]!=c2[id2]) ans+=b[i]-b[i-1];
    }
    cout<<ans/2;
    return 0;
}
