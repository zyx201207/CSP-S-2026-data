#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,sy=1,a[200005],we[200005],maxn;
bool f[200005];
//guanzhu bilibili dahongdou009
//guanzhu luogu 884813
//☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭☭
//❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂❂
void d(ll sd,ll z)
{
    if(sd>=m)
    {
        maxn=max(z,maxn);
        return;
    }
    for(ll i=1;i<=n;i++)
    {
        if(f[i]==0)
        {
            f[i]=1;
            d(sd+1,z&a[i]);
            f[i]=0;
        }
    }
    return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){f[i]=1;
    d(1,a[i]);f[i]=0;}
    cout<<maxn;
    return 0;
}
