#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000005];
int maxn=-1;
void dfs(int step,int tep,int ans){
    if(step==n+1){
        if(tep==m){
            maxn=max(maxn,ans);
        }
        return ;
    }
        int tp=tep+1;
        if(ans==0){
        ans=a[step];
        }
        int as=a[step]&ans;
    dfs(step+1,tp,as);
    dfs(step+1,tep,ans);
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(n==m){
        int st=a[1];
    for(int i=2;i<=n;i++){
        st=st&a[i];
    }
    cout<<st;
    return 0;
}
if(n-1==m){
    for(int i=1;i<=n;i++){
        int st=0;
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            if(st==0){
                st=a[j];
            }
            st=st&a[j];
        }
        maxn=max(maxn,st);
    }
    cout<<maxn;
    return 0;
}
if(m==2){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
    }
    cout<<maxn;
    return 0;
}
if(m==1){
    for(int i=1;i<=n;i++){
        maxn=max(maxn,a[i]);
    }
    cout<<maxn;
    return 0;
}
dfs(1,0,0);
cout<<maxn;
return 0;
}











