#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int ans,a[200005],f[200005];
bool vis[200005],is[200005];
void dfs(int x,int n,int m){
    if(x>m){
        int p=f[1];
        for(int i=2;i<=m;i++){
            p&=f[i];
        }
        ans=max(ans,p);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            f[x]=a[i];
            vis[i]=1;
            dfs(x+1,n,m);
            vis[i]=0;
        }
    }
}
bool check(int n){
    string s="";
    while(n){
        s=char(n%2+'0')+s;
        n/=2;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')return 1;
    }
    return 0;
}
bool specialA(int n){
    for(int i=1;i<=n;i++){
        if(check(a[i]))return 0;
    }
    return 1;
}
bool specialB(int n){
    if(!is[n])return 0;
    for(int i=1;i<=n;i++){
        if(a[i]!=i-1)return 0;
    }
    return 1;
}
bool specialC(int n){
    for(int i=1;i<=n;i++){
        if(a[i]>4)return 0;
    }
    return 1;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,t=1;
    cin>>n>>m;
    while(t<=200000)is[t]=1,t*=2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        dfs(1,n,m);
        cout<<ans;
        return 0;
    }
    if(m==1){
        int maxn=0;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    if(m==n){
        int p=a[1];
        for(int i=2;i<=n;i++){
            p&=a[i];
        }
        cout<<p;
        return 0;
    }
    if(m==2){
        int p=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                p=max(p,a[i]&a[j]);
            }
        }
        cout<<p;
        return 0;
    }
    if(m==n-1){
        sort(a+1,a+n+1);
        int p=0,xb=0;
        for(int i=1;i<=n;i++){
            if(check(a[i])){
                xb=i;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(i!=xb)p&=a[i];
        }
        cout<<p;
        return 0;
    }
    if(specialA(n)){
        sort(a+1,a+n+1);
        int p=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            p&=a[i];
        }
        cout<<p;
        return 0;
    }
    if(specialB(n)){
        for(int i=1;i<=n;i++){
            if(is[i])m--;
        }
        int p=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            if(!is[i])p&=a[i];
        }
        cout<<p;
        return 0;
    }
    if(specialC(n)){
        int cnt0=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0)cnt0++;
            if(a[i]==1)cnt1++;
            if(a[i]==2)cnt2++;
            if(a[i]==3)cnt3++;
            if(a[i]==4)cnt4++;
        }
        if(cnt2+cnt3>=m)cout<<2;
        else if(cnt1+cnt3>=m)cout<<1;
        else cout<<0;
    }
    sort(a+1,a+n+1);
    int p=a[n];
    for(int i=n-1;i>=n-m+1;i--){
        p&=a[i];
    }
    cout<<p;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
