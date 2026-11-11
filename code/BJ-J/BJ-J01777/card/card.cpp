#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],bk[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i],++bk[a[i]];
    for(int k=1;k<=n;++k){
        fill(bk+1,bk+n+1,0);
        deque <int> q;
        for(int i=k;i<=n;++i){
            if(!bk[a[i]]) q.push_back(a[i]),++bk[a[i]];
            else{
                // cerr<<"pop\n";
                // for(int t=1;t<=q.size();++t) cerr<<q.front()<<" ",q.push_back(q.front()),q.pop_front();
                // cerr<<"\n";
                while(!q.empty()){
                    --bk[q.back()];
                    if(bk[a[i]]==0){
                        ++bk[a[i]];
                        break;
                    }
                    q.pop_back();
                }
            }
            // cerr<<"bk: ";
            // for(int t=1;t<=m;++t) cerr<<bk[t]<<" ";
            // cerr<<"\n";
        }
        fill(bk+1,bk+n+1,0);
        while(!q.empty()){
            // cerr<<q.front()<<" ";
            if(bk[q.front()]){
                q.pop_front();
                continue;
            }
            ++ans[q.front()];
            bk[q.front()]=1;
            q.pop_front();
        }
        // cerr<<"\n";
    }
    for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
    cout.flush();
    return 0;
}