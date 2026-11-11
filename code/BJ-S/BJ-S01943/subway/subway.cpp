#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m,c,d,q,f2;
int w[500005];
int k[505],a[505][50005],t[505][50005];
ll dis[500005];
vector<int> vt[500005];
void xxx(int x,int y){
    for(int i=1;i<=m;i++)dis[i]=1e18;
    dis[x]=0;
    queue<int> q;
    q.push(x);
    while(q.size()){
        int r=q.front();
        q.pop();
        for(auto v:vt[r]){
            int at=0;
            for(int i=1;i<=k[v];i++){
                if(a[v][i]==r)at=i;
            }
            for(int i=1;i<=k[v];i++){
                int aa=a[v][i];
                if(dis[aa]>dis[r]+t[v][i]+t[v][at]){
                    q.push(aa);
                    dis[aa]=dis[r]+t[v][i]+t[v][at];
                }
            }
        }
    }
    cout<<w[x]+w[y]+dis[y]<<endl;
}
void xxx2(int x,int y){

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    while(cin>>c){
        cin>>n>>m>>d>>q;
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>a[i][j]>>t[i][j];
                vt[a[i][j]].push_back(i);
            }
            if(k[i]>2)f2=1;
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            xxx(x,y);
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
