//203899
//lucky fiiiiiish!
#include<bits/stdc++.h>
#define int long long
#define Test ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
const int maxn=500+10,maxm=5e5+10;
int st,ed,T;
int c,n,m,d,q,w[maxm],k[maxn];
short dis[maxn][maxm],a[maxn][maxm];
map<int,int> mp[maxm];
vector<int> g[maxm];
void bfs(){
    queue<pair<pair<int,int>,int>> q;
    for(int i=1;i<=n;i++){
        if(mp[i][st]){
            q.push({{i,st},0});
            dis[i][st]=0;
        }
    }
    while(!q.empty()){
            //cerr<<"DONE"<<endl;
        int a1=q.front().first.first,a2=q.front().first.second,ww=q.front().second; q.pop();
        if(ww>dis[a1][a2]) continue;
        //cout<<"DI"<<endl;
        a2=mp[a1][a2];
        for(int i=a2+1;i<=k[a1];i++){
            //cout<<dis[a1][a[a1][i]]<<' '<<dis[a1][a[a1][a2]]<<endl;
            if(dis[a1][a[a1][i]]>dis[a1][a[a1][a2]]){
                dis[a1][a[a1][i]]=dis[a1][a[a1][a2]];
                //cout<<i<<endl;
            }
        }
        for(int i=a2;i<=k[a1];i++){
            for(int j:g[a[a1][i]]){
                if(j!=a1){
                    //cout<<a[a1][i]<<' '<<j<<endl;
                    //cout<<dis[j][a[a1][i]]<<' '<<dis[a1][a[a1][i]]+1<<endl;
                    if(dis[j][mp[j][a[a1][i]]]>dis[a1][a[a1][a2]]+1){
                        //cout<<"JDIEJDJEIDJEIDIEJDIEJIDJIEJDJEID"<<endl;
                        dis[j][a[a1][i]]=dis[a1][a[a1][a2]]+1;
                        //cout<<j<<' '<<mp[j][a[a1][i]]<<' '<<dis[j][a[a1][i]]<<endl;
                        q.push({{j,a[a1][i]},dis[a1][a[a1][a2]]+1});
                    }
                }
            }
        }
    }
    return;
}
signed main(){
    Test
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++) cin>>w[i];

    if(c>=12 && c<=19){
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>a[i][j]>>T;
                mp[i][a[i][j]]=j;
                g[a[i][j]].push_back(i);
            }
        }
        while(q--){
            memset(dis,0x3f,sizeof(dis));
            int ans=dis[0][0];
            cin>>st>>ed;
            bfs();

            //for(int i=1;i<=n;i++){
            //    for(int j=1;j<=k[i];j++) cout<<dis[i][j]<<' ';
            //    cout<<endl;
            //}
            for(int i=1;i<=n;i++){
                if(mp[i][ed]) ans=min(ans,(int)dis[i][ed]);
            }
            ans+=2;
            cout<<ans*T+w[st]+w[ed]<<endl;
        }
    }
    return 0;
}
