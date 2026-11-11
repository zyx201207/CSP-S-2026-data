#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans[N],q[N],l;
void game(int num){
    for(int i=num;i<=n;++i){
        int f=0;
        for(int j=1;j<=l;++j){
            if(q[j]==a[i]){
                f=j;
                break;
            }
        }
        if(f)l=f-1;
        q[++l]=a[i];
    }
    for(int i=1;i<=l;++i)ans[q[i]]++;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        memset(q,0,sizeof q);
        l=0;
        game(i);
    }
    for(int i=1;i<=m;++i)cout<<ans[i]<<' ';
}
