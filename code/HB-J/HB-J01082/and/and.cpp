#include<bits/stdc++.h>
using namespace std;
int n,m,a[200007],ans=((1<<30)-1);
int cnt(int n){
    int ans=0;
    for(;n;n>>=1)
        if(n&1)
            ans++;
    return ans;
}
bool cmp(const int &a,const int &b){
    if(cnt(a)==cnt(b))
        return a>b;
    return cnt(a)>cnt(b);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=m;i++)
        ans&=a[i];
    cout<<ans;
    return 0;
}
