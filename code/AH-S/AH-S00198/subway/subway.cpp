#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],l[500005],r[500005],ans[500005],sum;
vector<pair<int,int> > p[500005];
vector<int> a[505];
vector<int> t[505];
void dij(int x){
    priority_queue<pair<int,int> > q;
    q.push({0,x});
    memset(ans,0x3f,sizeof(ans));
    ans[x]=0;
    while(!q.empty()){
        int h=-q.top().first,id=q.top().second;
        q.pop();
        for(int i=0;i<p[id].size();i++){
            int xl=p[id][i].first,my=p[id][i].second;
            for(int j=0;j<a[xl].size();j++){
                //cout<<xl<<"\n";
                int to=a[xl][j];
                if(ans[to]>ans[id]+t[xl][j]+t[xl][my-1]){
                    ans[to]=ans[id]+t[xl][j]+t[xl][my-1];
                    q.push({-ans[to],to});
                    //cout<<xl<<" "<<to<<" "<<t[xl][j]+t[xl][my-1]<<"\n";
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1,X,T;j<=k[i];j++){
            cin>>X>>T;
            a[i].push_back(X);
            t[i].push_back(T);
            p[X].push_back({i,j});
        }
    }
    for(int i=1;i<=q;i++){
        cin>>l[i]>>r[i];
        dij(l[i]);
        //for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
        //cout<<"\n";
        cout<<ans[r[i]]+w[l[i]]+w[r[i]]<<"\n";
    }


    return 0;
}
