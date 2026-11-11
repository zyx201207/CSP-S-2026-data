#include <bits/stdc++.h>
using namespace std;
int n,m,c,d,q;
int w[500005];
int dis[505][505];
struct node{
    vector<pair<int,int> > line;
}station[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    //cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        scanf("%d",&w[i]);
        //cin>>w[i];
    }
    for(int i = 1;i<=n;i++){
        int l;
        scanf("%d",&l);
        //cin>>l;
        for(int j = 1;j<=l;j++){
            int s,t;
            scanf("%d%d",&s,&t);
            //cin>>s>>t;
            station[s].line.push_back({t,i});
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dis[i][j] = 1e8;
        }
        dis[i][i] = 0;
    }
    for(int i = 1;i<=m;i++){
        node s = station[i];
        //cout<<"check:station"<<i<<endl;
        for(int j = 0;j<s.line.size();j++){
            for(int k = 0;k<s.line.size()&&k!=j;k++){
                dis[s.line[j].second][s.line[k].second] = min(dis[s.line[j].second][s.line[k].second],s.line[j].first+s.line[k].first);
                dis[s.line[k].second][s.line[j].second] = dis[s.line[j].second][s.line[k].second];
                //cout<<s.line[k].second<<" "<<s.line[j].second<<" "<<dis[s.line[k].second][s.line[j].second]<<endl;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    /*
    cout<<"________________"<<endl;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"________________"<<endl;
    */
    while(q--){
        int x,y;
        cin>>x>>y;
        vector<pair<int,int> > lx = station[x].line;
        vector<pair<int,int> > ly = station[y].line;
        int ans = 1e8;
        for(int i = 0;i<lx.size();i++){
            for(int j = 0;j<ly.size();j++){
                ans = min(ans,lx[i].first+ly[j].first+dis[lx[i].second][ly[j].second]);
                //cout<<lx[i].second<<" "<<ly[j].second<<" "<<ans<<endl;
            }
        }
        printf("%d\n",ans+w[x]+w[y]);
        //cout<<ans+w[x]+w[y]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
