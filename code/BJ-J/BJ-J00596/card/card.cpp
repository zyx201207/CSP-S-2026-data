#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using pi=pair<int,int>;
using vb=vector<bool>;
#define fi first
#define se second
vi a;
vi cf;
vi lst;
vi ans;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i,j;
    cin>>n>>m;
    a.resize(n+1);
    lst.resize(m+1,-1);
    ans.resize(m+1,0);
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=n;i>=1;i--)
    {
        if(lst[a[i]]==-1)
        {
            lst[a[i]]=i;
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            ans[a[j]]++;
            if(lst[a[j]]!=-1)
            {
                j=lst[a[j]];
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
/*
4 3
1 2 1 3
*/