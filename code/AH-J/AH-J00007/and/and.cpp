#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200010],n,k,mx,cnt;
bool v[200010];
void dfs(ll ans,ll x,ll t){
    if(x>k){
        mx=max(mx,ans);
        return;
    }
    for(int i=t+1;i<=n;i++){
        if(!v[i]){
            v[i]=1;
            dfs(ans&a[i],x+1,i);
            v[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)cnt=a[i];
        mx=max(mx,a[i]);
        cnt=cnt&a[i];
    }
    if(n<=2000){
        if(k==1){
            cout<<mx;
        }
        else if(k==2){
            mx=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    mx=max(mx,a[i]&a[j]);
                }
            }
            cout<<mx;
        }
        else if(k==n)cout<<cnt;
        else {
            mx=0;
            dfs((1<<30)-1,1,0);
            cout<<mx;
        }
    }
    else{
        sort(a+1,a+1+n);
        cout<<a[n-k+1];
    }
    return 0;
}
