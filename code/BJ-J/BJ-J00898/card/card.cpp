#include<iostream>
#define int long long
using namespace std;
int n,m;
int p[500005],q[500005],ans[300005];
void game(int x){
    int t[300005];
    for(int i=1;i<=m;i++){
        t[i]=0;
    }
    for(int i=x;i<=n;i++){
        t[p[i]]++;
        q[i]=p[i];
        if(t[p[i]]>1){
            for(int j=i-1;;j--){
                q[j]=0;
                t[p[j]]--;
                if(p[j]==p[i]){
                    break;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(t[i]==1){
            ans[i]++;
        }
    }
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        game(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
