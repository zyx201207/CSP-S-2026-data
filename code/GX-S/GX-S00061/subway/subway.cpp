#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int MAXN=600;
int w[MAXN];
struct Node{
    int to,id;
};
int main(){
    while(cin>>c){
        cin>>n>>m>>d>>q;
        for(int i=1;i<=m;++i)cin>>w[i];
        vector<Node>adj[MAXN];
        for(int i=1,k;i<=n;++i){
            cin>>k;
            for(int j=1,a,t,last_a;j<=k;++j){
                cin>>a>>t;
                if(j>1){
                    adj[last_a].push_back({a,i});
                    adj[a].push_back({last_a,i});
                }
                last_a=a;
            }
        }
    }
    return 0;
}
