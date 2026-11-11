#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],sum[N];
int maxx=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=a[i]+sum[i-1];
    for(int i=1,j=2;i<=n&&j<=n;)
    {
        if(a[j]*(j-i)-(sum[j-1]-sum[i-1])>m)
            i++;
        else
        {
            maxx=max(maxx,j-i+1);
            j++;
        }
    }
    cout<<maxx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
