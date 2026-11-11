#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[500005];
bool vis[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        vector<int>cards;
        for(int j=i;j<=n;j++){
            for(int k=0;k<cards.size();k++){
                if(cards[k]==a[j]&&vis[k]==0){
                    for(int l=k;l<cards.size();l++){
                        vis[l]=1;
                    }
                    break;
                }
            }
            cards.push_back(a[j]);
        }
        for(int i=0;i<cards.size();i++){
            if(!vis[i]){
                cnt[cards[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
