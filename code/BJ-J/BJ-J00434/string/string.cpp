#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long x=0,last=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        x+=a[i];
        if(b[i]==b[last])
        {
            a[last]+=a[i];
            a[i]=0;
        }
        else last=i;
    }
    long long ans=0;
    long long l=0,r=n+1;
    long long ll=0,lll=0,rr=0,rrr=0;
    char lc=' ';
    while(lll<x/2)
    {
        rr=ll=0;
        l++;
        ll+=a[l];
        lll+=a[l];
        lc=b[l];
        while(rrr<ll && r>l)
        {
            r--;
            rrr+=a[r];
            if(b[r]!=b[l])ans+=a[r];
        }
        rrr-=ll;
    }
    ans-=rrr;
    cout<<ans;
    return 0;
}
