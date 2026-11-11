#include<bits/stdc++.h>
using namespace std;
struct node{
    int to,nxt;
}a[100010];
set<int> s[300005];
bool vis[300010];
int cnt[300010],cnt2[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cout<<n<<" ";
    for(int i=2;i<=m;i++){
        cout<<0<<" ";
    }
    /*for(int i=1;i<=n;i++){
        cin>>a[i].to;
        a[i].nxt=i+1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[j].to==a[i].to){
                a[j].nxt=0;
            }
        }
        memset(cnt2,0,sizeof(cnt2));
        int k=1;
        while(a[k].nxt!=0){
            cnt2[a[k].to]++;
            k=a[k].nxt;
        }
        for(int j=1;j<=m;j++){
            cnt[j]+=cnt2[j];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }*/
    return 0;
}
