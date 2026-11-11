#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,m,mx=0;
LL cnt[(int)(3e5)+1],t[(int)(3e5)+1],a[(int)(5e5)+1];
void fuc(LL x)
{
    vector<LL> v;
    memset(t,0,sizeof(t));
    for(int i=x;i<=n;i++)
    {
        if(t[a[i]]>=1)
        {
            while(v[v.size()-1]!=a[i])
            {
                t[v[v.size()-1]]--;
                v.pop_back();
            }
        }
        else
        {
            v.push_back(a[i]);
            t[a[i]]++;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        cnt[v[i]]++;
    }
    return;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        fuc(i);
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<' ';
    }
    return 0;
}
