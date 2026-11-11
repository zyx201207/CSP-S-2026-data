#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans,pown[35];
bool f1=1,f2=1,f3;
void dfs(int pos,int x,int andd){
    if(x==m){
        ans=max(ans,andd);
        return;
    }
    if(pos>n){
        return;
    }
    dfs(pos+1,x+1,andd&a[pos]);
    dfs(pos+1,x,andd);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    pown[1]=1;
    for(int i=2;i<=30;i++){
        pown[i]=pown[i-1]*2;
    }
    for(int i=1;i<=n;i++){
        bool ff=0;
        cin>>a[i];
        for(int i=1;i<=30;i++){
            if(a[i]+1==pown[i]){
                ff=1;
                break;
            }
        }
        if(!ff){
            f1=0;
        }
        if(a[i]!=i-1){
            f2=0;
        }
    }
    for(int i=1;i<=30;i++){
        if(n==pown[i]){
            f3=1;
            break;
        }
    }
    if(f2&&f3){
        cout<<n-m<<"\n";
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans<<"\n";
        return 0;
    }
    if(m==n){
        ans=LLONG_MAX;
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans<<"\n";
        return 0;
    }
    if(f1){
        sort(a+1,a+1+n,greater<int>());
        cout<<a[m]<<"\n";
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans<<"\n";
        return 0;
    }
    dfs(1,0,LLONG_MAX);
    cout<<ans<<"\n";
    return 0;
}
