#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,maxa;
struct is{
    int b;
    string a;
}s[200100];
int f(int x){
    int cnt=1;
    for(int i=1;i<=n;i++){
        cnt*=2;
    }
    return cnt;
}
void d(int x){
    int sx=s[x].b;
    for(int i=30;i>=1;i--){
        if(sx>f(i)){
            sx-=f(i);
            s[x].a[i]='1';
        }else{
            s[x].a[i]='0';
        }
    }
    return;
}
int yu(string a,string s){
    int ans[31];
    int g=0;
    for(int i=30;i>=1;i--){
        if(a[i]==s[i]&&s[i]=='1'){
            ans[i]==1;
        }else{
            ans[i]==0;
        }
    }
    for(int i=30;i>=1;i--){
        g+=ans[i]*f(i);
    }
    return g;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i].b;
        maxn=max(maxn,s[i].b);
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    for(int i=1;i<=n;i++){
        d(i);
    }
    for(int i=1;i<=n-m;i++){
        for(int j=i;j<m;j++){
            maxa=max(maxa,yu(s[j].a,s[j-1].a));
        }
    }
    cout<<maxa;
    return 0;
}
