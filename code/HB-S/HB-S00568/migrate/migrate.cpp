#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int pos[N];
struct node{
    int len;
    string s;
};
vector<node> l;
void dfs(int x,int u,int v,int n,int d,string s){
    if(x==v){
        l.push_back((node){s.size(),s});
        return;
    }
    for(int nxt=x;nxt<=n;nxt++){
        if(abs(pos[nxt]-pos[x])<=d&&nxt!=x)
            dfs(nxt,u,v,n,d,s+(char)nxt);
    }
}
int main(){
    ios::sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>pos[i];
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                l.clear();
                if(u!=v){
                    string tmp="";
                    dfs(u,u,v,n,d,tmp+(char)u);
                    if(l.size()<2)
                        continue;
                    sort(l.begin(),l.end(),[](node a,node b){return a.len<b.len;});
                    int cnt=0;
                    for(int i=1;i<=l.size()-1;i++){
                        if(l[i].len==l[0].len&&l[i].s!=l[0].s)
                            cnt++;
                    }
                    if(cnt==2)
                        ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}