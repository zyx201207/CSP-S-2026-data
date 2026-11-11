#include<bits/stdc++.h>
using namespace std;
int n,ll=1,rr;
long long cnt,ans,l=1,r;
struct node
{
    long long a;
    char c;
}s[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].c;
        s[i].a+=s[i-1].a;
    }
    r=s[n].a,rr=n,cnt=r/2;
    long long le=s[ll].a,re=s[rr-1].a+1;
    while(ll<=rr)
    {
        if(le-l<r-re)
        {
            if(s[ll].c!=s[rr].c)ans+=le-l+1;
            ll++,r-=le-l+1,l=s[ll-1].a+1,le=s[ll].a;
        }
        else if(le-l>r-re)
        {
            if(s[ll].c!=s[rr].c)ans+=r-re+1;
            rr--,l+=r-re+1,r=s[rr].a,re=s[rr-1].a+1;
        }
        else
        {
            if(s[ll].c!=s[rr].c)ans+=le-l+1;
            ll++,l=s[ll-1].a+1,le=s[ll].a,rr--,r=s[rr].a,re=s[rr-1].a+1;
        }
    }
    cout<<ans;
    return 0;
}
