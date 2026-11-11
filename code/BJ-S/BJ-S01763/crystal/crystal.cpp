#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=500005;
using ll=long long;
int n;
ll m,p[maxn],pre[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>p[i];
    sort(p+1,p+n+1);
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+p[i];
    int ans=0;
    for(int i=1;i<=n;++i){
        int L=0,R=i-1;
        while(L<R){
            int mid=L+R+1>>1;
            ll tmp=(mid+1)*p[i]-(pre[i]-pre[i-mid-1]);
            if(tmp<=m)L=mid;
            else R=mid-1;
        }
        ans=max(ans,L+1);
    }
    cout<<ans;
    return 0;
}