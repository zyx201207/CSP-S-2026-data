#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f,n;
ll ans;
struct zzz{
    string c;
    ll a;
}s[3355306];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>f;
    n=1;
    for(int i=1;i<=f;i++)
    {
        ll x;
        string y;
        cin>>x>>y;
        if(i==1)s[n].a+=x,s[n].c=y;
        else if(y==s[n].c)s[n].a+=x;
        else n++,s[n].a+=x,s[n].c=y;
    }
   /* cout<<n<<"\n";
    for(int i=1;i<=n;i++)cout<<s[i].a<<' ';*/
    for(int i=1,j=n;i<=n/2;i++,j--)
    {
        if(s[i].a!=s[j].a&&s[i].c==s[j].c)
        {
            ans+=abs(s[i].a-s[j].a);
            if(s[i].a>s[j].a)s[i+1].a+=abs(s[i].a-s[j].a);
            else s[j-1].a+=abs(s[i].a-s[j].a);
        }
        else if(s[i].a==s[j].a&&s[i].c!=s[j].c)ans+=s[i].a;
        else if(s[i].a!=s[j].a&&s[i].c!=s[j].c)
        {
            ans+=max(s[i].a,s[j].a);
            if(s[i].a>s[j].a)s[i+1].a+=abs(s[i].a-s[j].a);
            else s[j-1].a+=abs(s[i].a-s[j].a);
        }
    }
    cout<<ans;
    return 0;
}//No Ac   Yellow or Orange
