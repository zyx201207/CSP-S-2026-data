#include<bits/stdc++.h>
using namespace std;
int and_(int a,int b){
    if(a==b)
        return a;
    string acnt,bcnt;
    while(a!=0){
        acnt= acnt + char((a%2)+'0');
        a/=2;
    }
    while(b!=0){
        bcnt= bcnt + char((b%2)+'0');
        b/=2;
    }
    int cnt=0,j=1;
    for(int i=0;i<max(acnt.size(),bcnt.size());i++){
        if(acnt[i]==bcnt[i])
            cnt+=j;
        j*=2;
    }
    return cnt;
}
int a[200005];
int n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int ans=0;
    ans=a[1];
    for(int i=2;i<=m;i++)
        ans=and_(ans,a[i]);
    cout<<ans;
    return 0;
}