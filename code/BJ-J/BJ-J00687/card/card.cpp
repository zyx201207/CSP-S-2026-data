#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int ans[500005];
int vis[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        vector<int> v;
        for(int j = 1;j<=m;j++){
            vis[j]=0;
        }
        for(int j = i;j<=n;j++){
            if(!vis[a[j]]){
                v.push_back(a[j]);
                vis[a[j]]=1;
            }
            else{
                while(*(v.end()-1)!=a[j]&&v.size()>0){
                    vis[*(v.end()-1)]=0;
                    v.pop_back();
                }
            }
        }
        for(int j = 0;j<v.size();j++){
            ans[v[j]]++;
        }
    }
    for(int c=1;c<=m;c++){
        cout<<ans[c]<<' ';
    }
    return 0;
}



