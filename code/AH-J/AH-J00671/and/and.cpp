#include <iostream>
using namespace std;
const int N=2e5+5;
int n,m,pos,p,ans;
bool s[N][35],vis[N];
bool _count(int k,int lim){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        if(s[i][k]) cnt++;
    }
    return cnt>=lim;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1,u;i<=n;i++){
        scanf("%d",&u);
        for(int j=29;j>=0;j--){
            if(u>=(1<<j)){
                u-=(1<<j);
                s[i][j]=true;
            }
        }
        //for(int j=29;j>=0;j--) cout<<s[i][j]<<' ';
        //putchar('\n');
    }
    for(int j=29;j>=0;j--){
        if(!_count(j,m)) continue;
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            if(!s[i][j]) vis[i]=true;
        }
        ans+=(1<<j);
    }
    cout<<ans;
    return 0;
}
