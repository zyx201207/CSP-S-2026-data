#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
vector<int> cs(m+1,0);
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    vector<int> xc(n+1,0);

    for(int i=0;i<n;i++){
        cin>>xc[i];
    }

    for(int i=0;i<n;i++){
        vector<bool> vis(n+1,0);
        for(int j=n;j>=i;j--){
            if(!vis[xc[j]]){
                bool flag=0;
                vector<bool> vis1(n+1,0);
                for(int k=j;k>=i;k--){
                    if(vis1[xc[k]]||xc[k]==xc[j]){
                        continue;
                    }
                    vis1[xc[k]]=1;
                    for(int q=j;q<=n;q++){
                        if(xc[k]==xc[q]){
                            k=i;
                            flag=1;
                        }
                    }
                }
                if(!flag){
                    cs[xc[j]]++;
                }
                vis[xc[j]]=1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cs[i]<<' ';
    }
    return 0;
}
