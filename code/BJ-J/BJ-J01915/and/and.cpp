#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m;
int a[N];
vector<int>p,np;
int ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],p.emplace_back(i);
    for(int i=29;~i;i--){
        int cnt=0;
        ans|=(1<<i);
        np.clear();
        for(int x:p)
            if((a[x]&ans)==ans)++cnt,np.emplace_back(x);
        if(cnt>=m){
            p.clear();
            for(int x:np)p.emplace_back(x);
        }else ans^=(1<<i);
    }
    cout<<ans;
    return 0;
}