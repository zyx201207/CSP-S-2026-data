#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6+5;

int n,m;
ll a[maxn];
bool b[maxn];

ll op[maxn];

void init(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);


    ios::sync_with_stdio(0);
    cin.tie(0);
    init();

    for(int i=1;i<=n;i++){
        vector<ll>u;
        for(int j=1;j<=m;i++)b[j] = 0;

        // break;
        for(int j=i;j<=n;j++){
            // break;

            if(b[a[j]]==0)u.push_back(a[j]);
            else{
                vector<ll>p;
                int k =0;
                for(k;k<u.size();k++){
                    if(u[k]==a[j])break;
                }
                for(int o=0;o<k;o++)p.push_back(u[o]);
                p.push_back(a[j]);
                u = p;
            }
        }
        for(auto &v : u)op[v]++;
    }    

    for(int i=1;i<=m;i++)cout<<op[i]<<" ";
    return 0;
}