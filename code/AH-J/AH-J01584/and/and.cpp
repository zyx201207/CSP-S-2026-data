#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f=1073741823,res;
void dfs(long long t,long long cnt,long long r){
    if(t==n){
        if(cnt==m){
            res=max(res,r);
        }
        return;
    }
    if(cnt>=m){
        return;
    }
    dfs(t+1,cnt+1,r&a[t]);
    dfs(t+1,cnt,r);
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    res=a[0];
    for(int i=1;i<n;i++){
        res&=a[i];
    }
    if(n<=20){
        dfs(0,0,f);
    }else if(n<=2000){
        if(m==1){
            for(int i=0;i<n;i++){
                res=max(res,a[i]);
            }
        }else if(m==2){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    res=max(res,a[i]&a[j]);
                }
            }
        }else if(m==n){
            res=a[0];
            for(int i=1;i<n;i++){
                res&=a[i];
            }
        }
    }
    cout<<res;
    return 0;
}
