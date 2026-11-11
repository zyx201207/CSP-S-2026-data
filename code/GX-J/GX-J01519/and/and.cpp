#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;

const int MAXN = 200005;

ll nbs[MAXN];
int n,m;
ll ans;

bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>nbs[i];
    sort(nbs,nbs+n,cmp);
    ans=nbs[0];
    for(int i=1;i<m;i++) ans &= nbs[i];
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
