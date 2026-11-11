#include<bits/stdc++.h>
#define int long long
using namespace std;
int cn[300011],t[500011],a[500011],ans[300011];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n;i>=1;i--)if(!cn[a[i]])cn[a[i]]=i;
    //for(int i=1;i<=m;i++)cout<<cn[i]<<" ";  OK
    for(int i=1;i<=n;i++)
    {
        ans[a[i]]+=1+t[i];
        if(cn[a[i]]==i)t[i+1]+=1+t[i];
        else t[cn[a[i]]+1]+=1+t[i];
    }
    for(int i=1;i<=m;i++)cout<<t[cn[i]+1]<<" ";
    return 0;
}
