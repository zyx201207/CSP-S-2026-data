#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bool vis[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int j=30;j>=0;j--){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            bool x=a[i]&(1<<j);
            if(x) cnt++;
        }
        if(cnt<m) continue;
        ans+=(1<<j);
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            bool x=a[i]&(1<<j);
            if(!x) vis[i]=1;
        }
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
I want to AK csp_j !
*/
