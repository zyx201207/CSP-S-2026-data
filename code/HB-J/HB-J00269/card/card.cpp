#include <bits/stdc++.h>
using namespace std;
const int N=5010;
int a[N];
int nxt[N];
int n,m;
int cnt[3010];
bool vis[3010];
void init(int st){
    for(int i=1;i<=3000;i++) vis[i]=0;
    for(int i=1;i<=n;i++){
        nxt[i]=0;
    }
    for(int j=1;j<=m;j++){
        int last=-1;
        for(int i=n;i>=st;i--){
            if(a[i]==j){
                if(last==-1){
                    nxt[i]=i;
                }else{
                    nxt[i]=last;
                }
                last=i;
            }
        }
    }

}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        init(i);
        for(int j=i;j<=n;j++){
            if(nxt[j]==j){
                vis[a[j]]=1;
            }else{


                j=nxt[j];
                vis[a[j]]=1;

            }
        }
        //cout<<i<<":"<<" ";
        for(int j=1;j<=3000;j++){
            if(vis[j]){
                cnt[j]++;
                //cout<<j<<" ";
            }
        }
        //cout<<"\n";
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    return 0;
}
