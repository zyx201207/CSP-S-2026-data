#include<bits/stdc++.h>
using namespace std;

struct tree{
    int mh;
    vector<int>s;
}p[100];

void dfs(int fa,int l,int h){
    p[l].mh=max(p[l].mh,h);
    for(int i=0;i<p[l].s.size();i++){
        if(p[i].s[l]==fa) continue;
        dfs(l,p[l].s[i],h+1);
    }
    return;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            p[a].s.push_back(b);
            p[b].s.push_back(a);
        }
        for(int i=1;i<=n;i++){
            dfs(0,i,0);
        }
        if(k>=n-1) cout<<0;
        else{
            int maxn=0;
            for(int i=1;i<=n;i++){
                maxn=max(maxn,p[i].mh);
            }
            if(maxn==1) cout<<1;
            else if(maxn==3) cout<<max(maxn-k+1,1);
            else cout<<maxn-k+1;
        }
    }//TmT
    return 0;
}
