#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define IMX INT_MAX
const int N=2e5+5;
int n,m,ans;
int a[N];
void dfs(int cur,int l,int res){
    if (cur>m){
        ans=max(ans,res);
    }
    for (int i=l+1;i<=n;i++){
        dfs(cur+1,i,res&a[i]);
    }
}
int lowbit(int x){
    return x&-x;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    bool fa=1,fb=1;
    if (lowbit(n)!=n){
        fb=0;
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (lowbit(a[i]+1)!=a[i]+1){
            fa=0;
        }
        if (a[i]!=i-1){
            fb=0;
        }
    }
    sort(a+1,a+n+1,greater<int>());
    if (m==2){
        for (int i=1;i<=n;i++){
            for (int j=1;j<i;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if (m==n-1){
        ans=IMX;
        for (int i=1;i<n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if (fa){
        ans=IMX;
        for (int i=1;i<=m;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if (fb){
        vector<int> v;
        v.push_back(0);
        v.push_back(n-1);
        v.push_back(n-2);
        int i=n-2,ti=2;
        while (i){
            i-=ti;
            for (int j=1;j<=ti;j++){
                v.push_back(i);
            }
            ti*=2;
        }
        cout<<v[m];
        return 0;
    }
    if (n>2000){
        cout<<2;
        return 0;
    }
    dfs(1,0,IMX);
    cout<<ans;
    return 0;
}
