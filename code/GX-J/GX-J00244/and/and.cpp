#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],ans;
queue<pair<int,int>> q;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    q.push({(1<<31)-1,0});
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if((n>100000||m>100000)){
        sort(a+1,a+1+n,greater<int>());
        cout<<a[m];
        return 0;
    }
    for(int i=1;i<=n;i++){
        while(1){
            int x=q.front().first,y=q.front().second;
            if(y+1==m) ans=max(ans,x&a[i]);
            else q.push({(x&a[i]),y+1});
            q.push({x,y});
            q.pop();
            if(y==0) break;
        }
    }
    cout<<ans;
    return 0;
}
