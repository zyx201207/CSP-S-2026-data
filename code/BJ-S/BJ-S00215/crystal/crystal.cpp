#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5;
int n,l,r,mid;
long long m,arry[MAXN+1];
bool check(int a)
{
    for(int i=a;i<=n;i++)
    {
        if((arry[i]-arry[i-1])*a-arry[i]+arry[i-a]<=m)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arry[i];
    }
    sort(arry+1,arry+1+n);
    arry[0]=0;
    for(int i=1;i<=n;i++)
    {
        arry[i]+=arry[i-1];
    }
    int l=1,r=n;
    while(l<r)
    {
        mid=(l+r+1)>>1;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}