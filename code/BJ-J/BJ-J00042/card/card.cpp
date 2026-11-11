#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=2e5+5;
ull ans[maxn];
ull n,m,dtk[maxn];
//ull v[maxn],v2[maxn],dt[maxn],vi=0,v2i=0,dti=0,dtk[maxn];
vector<ull> v,v2,dt;
void deskput()
{
    int k=v2.back();
    if(find(dt.begin(),dt.end(),k)==dt.end())
    {
        dt.push_back(k);
        dtk[k]=dt.size();
    }
    else
    {
        dt.erase(dt.begin()+dtk[k],dt.end());
    }
    //for(int j:dt)cout<<j<<' ';
    //cout<<'\n';
    v2.pop_back();
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        v2=v;
        v2.erase(v2.begin(),v2.begin()+i);
        dt.clear();
        fill(dtk,dtk+n,0);
        reverse(v2.begin(),v2.end());
        for(int j=0;j<n-i;j++)deskput();
        for(int j:dt)ans[j]++;
        //cout<<'\n';
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
