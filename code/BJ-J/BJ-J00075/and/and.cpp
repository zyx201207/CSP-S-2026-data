#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,maxn;
void check(int a){
    maxn=max(maxn,a);
    return;
}
void dfs(int step,int ans){
    if(step>m){
        check(ans);
        return;
    }
    for(int i=step;i<=n;i++){
        dfs(step+1,ans&a[i]);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    if(m==1){
        for(int i=1;i<=n;i++)
            ans=max(a[i],ans);
    }
    else if(m==2){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(a[i]&a[j],ans);
    }
    else if(a[1]&a[2]==a[1]or a[1]&a[2]==a[2]){
        sort(a+1,a+n+1);
        ans=a[n-m+1];
    }
    else if(n<=2000 and m==2000){
        ans=pow(2,21)-1;
        for(int i=1;i<=n;i++)
            ans&=a[i];
    }
    else{
        dfs(1,pow(2,21));
        ans=maxn;
    }
    cout << ans;
    return 0;
}
