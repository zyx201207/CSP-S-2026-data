#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=5e5;
int n,ans;
long long m,a[MAXN+10],s[MAXN+10];
inline bool cmp(int x,int y){return x>y;}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        s[i]=a[1]-a[i]+s[i-1];
    int j=1;
    for(int i=1;i<=n;i++)
    {
        while(s[i]-s[j-1]-(s[j]-s[j-1])*(i-j+1)>m)
            j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}
