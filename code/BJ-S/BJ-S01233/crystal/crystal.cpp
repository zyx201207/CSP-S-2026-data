#include<iostream>//hasn t check
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5e5+7;
ll n,m,a[N],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    ll l=0,cnt=0;
    for(int r=1;r<=n;r++)
    {
        cnt=cnt+(r-l)*(a[r]-a[r-1]);
        while(cnt>m)
        {
            cnt-=(a[r]-a[l]);
            l+=1;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
