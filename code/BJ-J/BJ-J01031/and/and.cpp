#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int check(int x){
    for(int i=1;i<=30;i++){
        if(x==pow(2,i)-1)
            return 1;
    }
    return 0;
}
int ans[200005];
int tmp=INT_MIN;//5 3 31 3 1 15 7
void dfs(int x,int sum){
    if(sum>m){
        int cnt=ans[1];
        for(int i=2;i<=m;i++)
            cnt&=ans[i];
        tmp=max(tmp,cnt);
        return ;
    }
    for(int i=x;i<=n;i++){
        ans[sum]=a[i];
        dfs(i+1,sum+1);
    }
    return ;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!check(a[i]))
            flag=0;
    }
    if(flag){
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
        return 0;
    }
    dfs(1,1);
    cout<<tmp;
    return 0;
}
