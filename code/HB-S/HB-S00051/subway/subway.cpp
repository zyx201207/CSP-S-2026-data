#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i = a;i <= b;i++)
using namespace std;
int c,n,m,d,q;
int w[500005],k[500005];
struct node{
    int id;
    int ti;
};
vector<node> st;
vector<node> li;
int ans = 1000000;
bool sf[500005];

void dfs(int la,int tot,int dq){
    if(dq == la){
        tot += li[dq].ti;
        tot += w[dq];
        ans = min(tot,ans);
        tot -= li[dq].ti;
        tot -= w[dq];
        return ;
    }
    tot += li[dq].ti;
    for(auto u:st){
        if(sf[u.id]){
            sf[u.id] = false;
            tot += u.ti;
            dfs(la,tot,u.id);
            tot -= u.ti;
        }
    }
    tot -= li[dq].ti;
    return ;

}

int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    rep(i,1,m){
        cin >> w[i];
    }
    rep(i,1,n){
        cin >> k[i];
        rep(j,1,k[i]){
            int a,t;
            cin >> a >> t;
            st.push_back({a,t});
            li.push_back({i,t});
        }
    }

    while(q--){
        int x,y;
        cin >> x >> y;
        memset(sf,true,sizeof(sf));
        ans = 1000000;
        dfs(y,w[x],x);
        cout << ans << endl;
    }

    return 0;
}
