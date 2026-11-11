#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,M;
int a[500010],b[500010];
map<int,int>m[500010];
vector<int>v[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>M;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        for(ll j=0;j<=i;j++)
        {
            if(m[j][a[i]]==0)
            {
                v[j].push_back(a[i]);
                m[j][a[i]]=v[j].size();
            }
            else
            {
                ll vs=v[j].size(),v1=vs-m[j][a[i]];
                while(v1--)
                {
                    vs--;
                    m[j][v[j][vs]]=0;
                    v[j].pop_back();
                }
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<v[i].size();j++)
        {
            b[v[i][j]]++;
        }
    }
    for(ll i=1;i<=M;i++)
    {
        cout<<b[i]<<' ';
    }
    return 0;
}
