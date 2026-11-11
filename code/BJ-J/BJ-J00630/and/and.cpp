#include<iostream>
using namespace std;
long long a[200005];
int ans;
int n,m;
void ilm(int i,int onl,int ma)
{
    if(onl==0)
    {
        ans=max(ans,ma);
        return ;
    }
    for(int j=i;j<=n;j++)
    {
        ilm(j+1,onl-1,(ma&a[j]));
    }
    return ;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-m+1;i++)
    {
        ilm(i+1,m-1,a[i]);
    }
    cout<<ans;
    return 0;
}
