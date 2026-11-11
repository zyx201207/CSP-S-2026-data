#include<bits/stdc++.h>
using namespace std;
const int N=5e5+13267;
int c,n,m,d,q,k,st,ti,ans;
int w[N];
bool tr[N];
vector<int>a[501],t[501],li[N],hp[N];
void plan(int x,int y){
    for(int i=0;i<li[x].size();i++){
        int line=li[x][i];
        ans+=hp[x][i];
        for(int j=0;j<(a[line].size());j++){
            int station=a[line][j];
            if(station==y){
                ans+=t[line][j]+w[y];
                return;
            }
        }
        ans-=hp[x][i];
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int x,y;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>st>>ti;
            a[i].push_back(st);
            t[i].push_back(ti);
            if(!li[st].empty())tr[st]=1;
            li[st].push_back(i);
            hp[st].push_back(ti);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans=w[x];
        plan(x,y);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
