#include<iostream>
#include<cmath>
using namespace std;
int n,m,a[200010];
int l[200010]={};
bool used[200010]={};
int f(int k)
{
    if(k==m)
    {
        int ret=l[0];
        for(int i=1;i<k;i++)
        {
            ret=ret&l[i];
        }
        return ret;
    }
    int maxn=-1e9;
    for(int i=1;i<=n;i++)
    {
        if(used[i])continue;
        used[i]=true;
        l[k]=a[i];
        maxn=max(maxn,f(k+1));
        used[i]=false;
    }
    return maxn;
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
    cout<<f(0);
    return 0;
}
