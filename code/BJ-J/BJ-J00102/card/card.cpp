#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2e5+10;
int n,m,a[N],ans=0;
vector<int> v;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    int k=0;
    while(m--)
    {
        k++;
        for(int i=k; i<n; i++)
        {
            if(v.empty()) 
            {
                v.pb(a[i]);
                continue;
            }
            for(int j=0; j<v.size(); j++)
            {
                if(v[j]==a[i])
                {
                    for(int o=j; o<v.size(); o++) v[o]=-114514;
                    break;
                }
            }
            v.pb(a[i]);
        }
        for(int i=0; i<v.size(); i++)
        {
            if(v[i]==-114514) continue;
            if(v[i]==k) ans++;
        }
        cout<<ans<<" ";
        ans=0;
    }
    return 0;
}