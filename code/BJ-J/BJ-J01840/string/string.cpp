#include <iostream>
using namespace std;
const int MAXN=2e5;
int l,r,s=1,t;
int n,a[MAXN+10];
char c[MAXN+10];
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    t=n;
    while(s<t)
    {
        int res=min(a[s]-l,a[t]-r);
        if(c[s]!=c[t])
            ans+=res;
        if(a[s]-l<a[t]-r)
        {
            r+=a[s]-l;
            l=0;
            s++;
        }
        else if(a[s]-l>a[t]-r)
        {
            l+=a[t]-r;
            r=0;
            t--;
        }
        else
        {
            l=r=0;
            s++;
            t--;
        }
    }
    cout<<ans;
    return 0;
}
