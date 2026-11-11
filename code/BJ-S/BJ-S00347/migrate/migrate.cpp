#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d;
long long x[N],maxn[N],gett[N];
vector<int> g[N];
void find(int x,long long o){
    for(int i=0;i<g[x].size();i++){
        int v=g[x][i];
        if(o<maxn[v]){
            gett[v]=1;
            maxn[v]=o;
        }else if(o==maxn[v]){
            gett[v]++;
        }else{
            return;
        }
        find(g[x][i],o+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    cin>>c>>t;
    freopen("migrate.out","w",stdout);
    while(t--){
        cin>>n>>d;
        long long sum=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(x[i]+d>=x[j]&&x[i]<x[j]){
                    g[i].push_back(j);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) maxn[j]=1e3;
            find(i,0);
            for(int j=i;j<=n;j++){
                if(gett[j]==2) sum++;
                gett[j]=0;
                maxn[j]=0;
            }
            g[i].clear();
        }
        cout<<sum<<endl;
    }
}