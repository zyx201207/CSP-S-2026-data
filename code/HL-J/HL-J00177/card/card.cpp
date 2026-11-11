#include<bits/stdc++.h>
using namespace std;
const int N=500010,M=300010;
int mp[M],a[N],vis[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        s.clear();
        memset(vis,0,sizeof(vis));
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                s.insert(a[j]);
                vis[a[j]]=j;
            }
            else{
                for(int k=vis[a[j]];k<=j;k++){
                    s.erase(a[k]);
                    vis[a[k]]=0;
                }
                s.insert(a[j]);
                vis[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++){
            if(s.find(j)!=s.end()){
                mp[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<mp[i]<<' ';
    }
    return 0;
}
