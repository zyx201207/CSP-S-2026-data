#include <bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,m,a[N],ans=0,man=n;
bool tr[N];
void solve(){
    int k=30;
    while(k>=0){
        //if(man<m)return;
        int ji=0;
        for(int i=1;i<=n;i++){
            if(tr[i]==1)continue;
            if(a[i]&(1<<k))ji++;
        }
        if(ji>=m){
            for(int i=1;i<=n;i++){
                if(tr[i]==1)continue;
                if((a[i]&(1<<k))==0)tr[i]=1;
            }
            ans|=1<<k;
        }
        k--;
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    solve();
    cout<<ans;
    return 0;
}
