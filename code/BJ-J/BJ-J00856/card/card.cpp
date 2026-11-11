#include <bits/stdc++.h>

using namespace std;
int a[500005],vis[500005],cnt[500005];
stack<int> s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(!vis[a[j]]){
                vis[a[j]]++;
                s.push(a[j]);
            }else{
                while((s.size())&&(s.top()!=a[j])){
                    vis[s.top()]=0;
                    s.pop();
                }
                if(s.size()) s.pop();
                s.push(a[j]);
            }
        }
        while(s.size()){
            cnt[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
