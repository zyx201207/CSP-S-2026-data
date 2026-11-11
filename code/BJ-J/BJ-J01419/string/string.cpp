#include <bits/stdc++.h>
using namespace std;
int n;
long long len,ans;
long long a[200005],l[200005],r[200005];
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i]>>c[i];
        l[i]=len+1;
        len+=a[i];
        r[i]=len;
        //cout<<"l["<<i<<"]="<<l[i]<<" ";
        //cout<<"r["<<i<<"]="<<r[i]<<endl;
    }
    for (int i=1;i<=n;++i)
    {
        //cout<<"i="<<i<<":\n";
        if (l[i]>len/2)break;
        long long l1=l[i],r1=r[i];
        r1=min(r1,len/2);
        long long l2=len-r1+1,r2=len-l1+1;
        //cout<<"l1="<<l1<<" r1="<<r1<<endl;
        //cout<<"l2="<<l2<<" r2="<<r2<<endl;
        int _l=lower_bound(r+1,r+n+1,l2)-r;
        int _r=lower_bound(r+1,r+n+1,r2)-r;
        //cout<<"_l="<<_l<<" _r="<<_r<<endl;
        if (_l==_r)
        {
            if (c[_l]!=c[i])
            {
                ans+=r2-l2+1;
            }
        }
        else
        {
            if (c[_l]!=c[i])
            {
                ans+=r[_l]-l2+1;
                //cout<<"ans="<<ans<<endl;
            }
            if (c[_r]!=c[i])
            {
                ans+=r2-l[_r]+1;
                //cout<<"ans="<<ans<<endl;
            }
        }
        for (int j=_l+1;j<_r;++j)
        {
            if (c[j]!=c[i])
            {
                ans+=a[j];
                //cout<<"ans="<<ans<<endl;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}