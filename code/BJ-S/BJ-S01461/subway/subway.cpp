#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
vector<ll> sta[555];
vector<ll> sub[555];
ll t[555];
ll tp[555][555];
ll k[555],l[555],r[555];
ll ds[555][555],mine[555][555];
bool have_s[555][555];
bool vsta[505][505];
bool vline[505];
bool transfer[505][505];//transfer[i][j]=1 refers to i-->j performed
ll pp;
bool cmp(ll x,ll y){
    return x>y;
}
void dfs(int now,int nowl,int id,ll &val,int fa,int prel,ll &minn){
    //cout<<"now at "<<now<<' '<<"now line is "<<nowl<<'\n';
    vsta[now][nowl]=1,vline[nowl]=1;
    if(now==r[id]){
        minn+=+t[now]+tp[nowl][r[id]];
        val=min(val,minn);
        //cout<<"arrive,ans="<<minn<<'\n';
        return;
    }
    //cout<<"now connect:";
    //for(int i:sub[now]) cout<<i<<' ';
    //cout<<'\n';
    for(int i:sub[now]){
        if(i==nowl){
             for(int j:sta[nowl]){
                if(j==now||vsta[j][nowl]||j==fa) continue;
                dfs(j,nowl,id,val,now,nowl,minn);
            }
        }else{
            ll xx=minn;
            if(!transfer[nowl][i]){
                transfer[nowl][i]=1;
                //cout<<"up time:"<<tp[nowl][now]<<" down time:"<<tp[i][now]<<'\n';
                //cout<<"now line:"<<nowl<<" next line:"<<i<<'\n';
                ll p=minn;
                minn+=tp[nowl][now]+tp[i][now];
                //cout<<"now time:"<<minn<<'\n';
                //cout<<"transfer "<<nowl<<" "<<i<<" has performed\n";
                dfs(now,i,id,val,now,nowl,minn);//now at j station,now line is i
                minn=xx;
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>t[i];
    memset(mine,0x3f,sizeof mine);
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            ll x;
            cin>>x;
            have_s[x][i]=1,sta[i].push_back(x);
            sub[x].push_back(i);
            cin>>tp[i][x];
        }
    }
    //cout<<have_s[2][2]<<'\n';
    for(int i=1;i<=m;i++) sort(sub[i].begin(),sub[i].end(),cmp);
    for(int i=1;i<=q;i++){
        cin>>l[i]>>r[i];
        ll ans=0x3f3f3f3f3f3f3f3f;
        for(int line=1;line<=n;line++){
            if(have_s[l[i]][line]){
                 memset(vsta,0,sizeof vsta),memset(transfer,0,sizeof transfer);
                //cout<<"now plan:"<<i<<'\n';
                ll minn=t[l[i]]+tp[line][l[i]];
                dfs(l[i],line,i,ans,0,i,minn);
                //cout<<'\n';
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}