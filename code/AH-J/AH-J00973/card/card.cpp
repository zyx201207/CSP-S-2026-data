#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
bool num[300015];
bool nu[300015];
ll nun[300015];
stack<ll> s;
vector<ll> c; 
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(nun,0,sizeof(nun));
    memset(num,false,sizeof(num));
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
    {
        ll j;
        cin>>j;
        c.push_back(j);
        num[j]=true;
    }
    memset(nu,false,sizeof(nu));
    for (ll i=1;i<=n;i++)
    {
        for (ll j=i;j<=n;j++)
        {
            if (nu[c[j]]==true)
            {
                while (s.top()!=c[j])
                {
                    nu[s.top()]=false;
                    s.pop();
                }
            }
            else
            {
                nu[c[j]]=true;
                s.push(c[j]);
            }
        }
        while (!s.empty())
        {
            nu[s.top()]=false;
            nun[s.top()]++;
            s.pop();
        }
    }
    for (ll i=1;i<=m;i++)
    {
        if (num[i]==true)
            cout<<nun[i]<<" ";
    }
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
}