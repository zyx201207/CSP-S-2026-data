#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2e5,MAXLG=30;
long long a[MAXN+5];
int p[MAXLG+5];
long long lg(long long x)
{
    long long res=0;
    while(x>0)
    {
        ++res;
        x>>=1;
    }
    return res-1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,greater<int>());
    int ll=31;
    for(int i=1;i<=n;++i)
    {
        if(lg(a[i])<ll)
        {
            ll=lg(a[i]);
            p[ll]=i;
        }
    }
    long long ans=-1;
    for(int i=MAXLG;i>=0;--i)
    {
        if(p[i]+m-1>n)
        {
            continue;
        }
        long long res=a[p[i]];
        for(int j=p[i]+1;j<=p[i]+m-1;++j)
        {
            res&=a[j];
        }
        ans=max(ans,res);
    }
    cout<<ans;
    return 0;
}
