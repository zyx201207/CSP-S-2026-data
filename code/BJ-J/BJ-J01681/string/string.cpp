#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll n,a[maxn],st[maxn],ed[maxn],len,led,rst,l,r,sum,ans;
char c[maxn];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        st[i]=len+1;
        len+=a[i];
        ed[i]=len;
    }
    if(len%2==0) led=len/2,rst=len/2+1;
    else led=(len+1)/2-1,rst=(len+1)/2+1;
    l=lower_bound(ed+1,ed+1+n,led)-ed;
    r=lower_bound(ed+1,ed+1+n,rst)-ed;
    //cout<<l<<" "<<r<<endl;
    for(int i=r;i<=n;i++)
    {
        ll pos=(len+1)-ed[i];
        while(st[l]>pos)
        {
            if(c[i]!=c[l]) ans+=min(led,ed[l])-st[l]+1;
            l--;
        }
        if(c[i]!=c[l]) ans+=min(led,ed[l])-max(st[l],pos)+1;
        led=pos-1;
       // cout<<i<<" "<<ans<<endl;
    }
    //if(l!=0) cout<<"WA"<<endl;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
