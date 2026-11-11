#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long ans;
long long a[N];
bool vis[N][40];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vis[i][31]=1;
    }
    int lst=31;
    for(int k=30;k>=0;k--){
        int cnt=0;
        long long x=1<<k;
        for(int i=1;i<=n;i++){
            if((vis[i][lst])&&(a[i]&x)){
                vis[i][k]=1;
                cnt++;
            }
        }
        if(cnt<m) continue;
        ans+=x;
        lst=k;
    }
    cout<<ans;
    return 0;
}
