//not true

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=1e8+5;
ll n,m;
ll ans=-1;
ll sum=2147483647;
ll book[MAXN]={0};
ll a[MAXN];
ll num=0x3f3f3f3f3f3f3f3f3f;
void dfs(ll x){
    if(x==m+1){
        ans=max(ans,sum);
        return ;
    }
    for(int i=0;i<n;i++){
        if(book[a[i]]==0){
            ll o=sum;
            if(sum&=a[i]<=ans){
                continue;
            }
            sum&=a[i];
            book[a[i]]=1;
            ll k=x++;
            dfs(k);
            book[a[i]]=0;
            sum=o;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
