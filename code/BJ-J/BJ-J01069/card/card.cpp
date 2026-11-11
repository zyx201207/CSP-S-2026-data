#include<bits/stdc++.h>
using namespace std;

int a[500005];
bool vis[300005];
int cnt[300005];
int now[500005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        int k=0;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==1){
                while(now[k]!=a[j]){
                    vis[now[k]]=0;
                    k--;
                }
                k--;
            }
            k++;
            now[k]=a[j];
            vis[a[j]]=1;
        }
        for(int j=1;j<=k;j++){
            cnt[now[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout << cnt[i] << " ";
    }
    return 0;
}
