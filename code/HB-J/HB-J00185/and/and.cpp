#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx=-1;
int aa[105],bb[105];
int And(int x,int y){
    if(x==y) return x;
    int l1=0,l2=0,s=0;
    if(x<y) swap(x,y);
    for(int i=1;i<=100;i++){
        aa[i]=bb[i]=0;
    }
    while(x>0){
        aa[++l1]=x%2;
        x/=2;
    }
    while(y>0){
        bb[++l2]=y%2;
        y/=2;
    }
    for(int i=1;i<=l1;i++){
        if(aa[i]==0||bb[i]==0) aa[i]=0;
    }
    for(int i=1;i<=l1;i++){
        s+=pow(2,i-1)*aa[i];
    }
    return s;
}
void dfs(int k,int ans,int cnt){
    if(cnt==m){
        maxx=max(maxx,ans);
        return;
    }
    for(int i=k;i<=n;i++){
        dfs(k+1,And(a[k],ans),cnt+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<n;i++){
        dfs(i,a[i],0);
    }
    cout << maxx;
    return 0;
}
