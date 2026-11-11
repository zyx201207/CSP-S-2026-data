#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n;
const int MAXN=2e5+10;
LL l[MAXN],r[MAXN];
char c[MAXN];
LL nowl=1;
LL len;
LL dl,dr;
LL ans;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        string s;
        cin>>x>>s;
        l[i]=nowl;
        r[i]=nowl+x-1;
        nowl+=x;
        c[i]=s[0];
        len+=x;
    }
    dl=(len+1)/2;
    if(len%2==0)
    {
        dr=dl+1;
    }
    else dr=dl;;
    for(int i=1;i<=n;i++)
    {
        if(l[i]>=dr&&r[i]>=dr)
        {
            LL nr=len-l[i]+1;
            LL nl=len-r[i]+1;
            LL nr2=nr,nl2=nl;
            nl=upper_bound(l+1,l+1+n,nl)-l-1;
            nr=lower_bound(r+1,r+1+n,nr)-r;
            for(int j=(int)nl;j<=(int)nr;j++)
            {
                if(c[j]!=c[i])
                {
                    ans+=min(nr2,r[j])-max(nl2,l[j])+1;
                }
            }
        }
        else if(l[i]<=dl&&r[i]>=dr&&len-r[i]+1<l[i])
        {
            LL nr=l[i]-1;
            LL nl=len-r[i]+1;
            LL nr2=nr,nl2=nl;
            nl=upper_bound(l+1,l+n+1,nl)-l-1;
            nr=lower_bound(r+1,r+1+n,nr)-r;
            for(int j=(int)nl;j<=(int)nr;j++)
            {
                if(c[j]!=c[i])
                {
                    ans+=min(nr2,r[j])-max(nl2,l[j])+1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}