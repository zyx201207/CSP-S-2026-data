#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],vis[500005],mx,r=1,x[100005],y[100005],x1,y11,mn;
vector<pair<int,int>> a[500005];
void abc(){
    mn=-1;
    for(int i=1;i<=m;i++)vis[i]=-1;
    vis[x1]=0;
    queue<int> q;
    q.push(x1);
    while(!q.empty()){
        long long b=q.front();
        if(b==y11){
            if(mn==-1)mn=vis[q.front()];
            mn=min(mn,vis[q.front()]);
        }
        for(int i=0;i<a[b].size();i++){
            if(vis[a[b][i].first]==-1||vis[q.front()]+a[b][i].second<vis[a[b][i].first]){
                vis[a[b][i].first]=vis[q.front()]+a[b][i].second;
                q.push(a[b][i].first);
            }
        }
        q.pop();
    }
    cout<<w[x1]+w[y11]+mn<<endl;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>x[j]>>y[j];
            for(int l=1;l<j;l++){
                a[x[l]].push_back({x[j],y[l]+y[j]});
                a[x[j]].push_back({x[l],y[l]+y[j]});
            }
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x1>>y11;
        abc();
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}
