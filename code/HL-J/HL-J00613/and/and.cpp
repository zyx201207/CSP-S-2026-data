#include <bits/stdc++.h>
using namespace std;
/*
贪心
\应该尽量让高位的1出现
第一个出现数量>=m的位应保住

*/
const int N=2*1e5+5;
bool vis[N];
int a[N];
int n,m;
int f(){
    int res=0;
    int b=31;
    int factor=1<<30;
    while(b>0){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]) continue;
            if(a[i] & factor) cnt++;

        }


        if(cnt<m) {
            b--;
            factor>>=1;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]) continue;
            if(!(a[i] & factor)) vis[i]=false;
        }

        res+=factor;
        b--;
        factor>>=1;
    }
    return res;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(vis,1,sizeof(vis));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<f();
    return 0;
}
