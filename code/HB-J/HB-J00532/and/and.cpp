#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[2000005],b[200005];
int get(){
    int tot,cnt=0,fl=0;
    for(int i=1;i<=n;i++){
       // cout<<b[i]<<' ';
        if(cnt==m)break;
        if(b[i]==1){
            //cout<<1;
            if(!fl){
                 tot=a[i];
                 fl=1;
            }
            else tot&=a[i];
            //cout<<tot<<' ';
            cnt++;
        }
    }
    //cout<<'\n';
    return tot;
}
void dfs(int x,int tot){
    if((n-x)+1<m-tot)return ;
    if(tot>=m){
        ans=max(ans,get());
        return;
    }
    //cout<<1;
    if(x>n)return ;
        // for(int i=1;i<=n;i++){
        //     cout<<b[i]<<' ';
        // }
        
        // cout<<'\n';
    b[x]=0;
    dfs(x+1,tot);
    b[x]=1;
    dfs(x+1,tot+1);
    b[x]=0;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>20){
        if(m==n){
        for(int i=2;i<=n;i++)a[1]&=a[i];
        cout<<a[1];
        return 0;
    }else if(m==1){
        int maxx=-1;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
        return 0;
    }else if(m==2){
        int maxx=-1;
        sort(a+1,a+n+1);
        for(int i=n;i>=2;i--){
            maxx=max(maxx,a[i]&a[i-1]);
        }
        cout<<maxx;
    }
    else if(n>2000){
        sort(a+1,a+n+1);
        for(int i=n-1;i>=n-m+1;i--){
            a[n]&=a[i];
        }
        cout<<a[n];
    }
    return 0;
    }
    
    dfs(1,0);
    //cout<<1;
    cout<<ans<<'\n';
}