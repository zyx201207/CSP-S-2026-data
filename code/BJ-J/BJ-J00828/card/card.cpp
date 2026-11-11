#include<bits/stdc++.h>
using namespace std;
int a[500010],cnt[300010],h[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++,h[a[i]]=i;
    }
    int mi=n+1;
    for(int i=1;i<=m;i++) mi=min(mi,h[i]);
    int add=0;
    for(int i=mi;i<=n;i++){
        int v=cnt[a[i]];
        cnt[a[i]]+=add,add+=v;
        if(h[a[i]]!=i){
            int t=h[a[i]];
            for(int j=i+1;j<t;j++){
                if(h[a[j]]==j) cnt[a[i]]+=cnt[a[j]],add+=cnt[a[j]];
            }
            //cout<<cnt[a[i]];
            i=t;
        }
        //else cout<<cnt[a[i]];
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
    cout<<"\n";
    return 0;
}