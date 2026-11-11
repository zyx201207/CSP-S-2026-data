#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m;
long long a[500050],b[500050];
bool fst;
bool sx(int x,int y)
{
    return x<y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,sx);
    for(int i=1;i<=n;i++)
    {
        long long ccz=(a[i]-a[i-1])*(i-1);
        if(ccz+b[i-1]<=m)
        {
            ans=i;
            b[i]=ccz+b[i-1];
        }
        else
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}