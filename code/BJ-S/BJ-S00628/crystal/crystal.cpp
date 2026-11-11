#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,ans=1;
const int maxN=5e5+10;
int a[maxN];
struct sba
{
    int ab;
    int lstn;
}cha[maxN];

bool cmp(sba x,sba y)
{
    return x.ab<=y.ab;
}

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(i!=1)
        {
            cha[i].ab=abs(a[i]-a[i-1]);
            cha[i].lstn=i;
        }
    }
    cha[1].ab=LONG_MAX;
    while(m)
    {
        sort(cha+1,cha+n+1,cmp);
        if(cha[1].ab>m||cha[1].ab==LONG_MAX)
            break;
        cha[1].ab=LONG_MAX;
        int fir=cha[1].lstn-1,sec=cha[1].lstn;
        if(a[fir]<=a[sec])
        {
            a[fir]+=cha[1].ab;
            if(fir!=1)
                cha[fir].ab=abs(a[fir]-abs(a[fir-1]));
        }
        else
        {
            a[sec]+=cha[1].ab;
            cha[sec+1].ab=abs(a[sec+1]-abs(a[sec]));
        }
        ans++;
        m-=cha[1].ab*ans;
    }
    cout<<ans;
    return 0;
}
