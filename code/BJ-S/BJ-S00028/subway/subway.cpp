#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
int CFF_Data_shen_mi_bian_liang;//heyiwei?
ll n,m,d,q,ans;
vector<ll>w,v[500005],t[505],u[505];
vector<pair<ll,ll>>h[505];
bool f[505];
void dfs(int p,int tg,ll dd,int nl){
    if(f[nl])return;
    f[nl]=1;
    dd+=t[nl][p];
    auto pos=find(u[nl].begin(),u[nl].end(),tg);
    if(pos!=u[nl].end()){
        ans=min(ans,dd+t[nl][tg]);
        return;
    }
    for(auto o:h[nl]){
        dfs(o.first,tg,dd+t[nl][o.first],o.second);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>CFF_Data_shen_mi_bian_liang;
    cin>>n>>m>>d>>q;
    w.resize(m+1);
    for(int i=1;i<=m;i++)cin>>w[i];//st_out:time
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        t[i].resize(m+1);
        for(int j=1;j<=k;j++){
            int x;
            ll y;
            cin>>x>>y;
            t[i][x]=y;//li_st:time
            v[x].push_back(i);//st->line
            u[i].push_back(x);//line->st
        }
    }
    for(int i=1;i<=n;i++){
        for(ll j:u[i]){
            if(v[j].size()>1){
                for(ll p:v[j]){
                    if(p==i)continue;
                    h[i].push_back({j,p});//line->st,line
                }
            }
        }
    }
    while(q--){//Duo_ce_yao_qing_kong!
        ans=LLONG_MAX;
        int sx,sy;
        cin>>sx>>sy;
        for(auto b:v[sx]){
            for(int i=1;i<=n;i++)f[i]=0;
            dfs(sx,sy,0,b);
        }
        cout<<ans+w[sx]+w[sy]<<"\n";
    }
    return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3



































wo yao shang luo gu bang!

Subway problem!

bx2027bx2027bx2027bx2027bx2027bx2027bx2027bx2027bx2027bx2027bx2027bx2027bx2027bx2027bx2027
Trick||Treat!Trick||Treat!Trick||Treat!Trick||Treat!Trick||Treat!Trick||Treat!Trick||Treat!
cpp14cpp14cpp14cpp14cpp14cpp14cpp14cpp14cpp14cpp14cpp14cpp14cpp14cpp14cpp14cpp14cpp14cpp14
Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?

I think CFF has trained by CRAS: there are two problems of traffic.

CR is going to be known!!!

==-CR.yt_qwq-id_823830==
*/