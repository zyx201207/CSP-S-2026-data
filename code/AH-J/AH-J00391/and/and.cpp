#include<bits/stdc++.h>
using namespace std;
int m,n;
long long s[2000009];
long long mx=-1;
void dfs(long long zh,int gs,int num){
    if(gs==n){
        mx=max(mx,zh);
        return ;
    }
    if(num==m)return ;
    for(int i=num;i<=m;i++){
             dfs(zh,gs,++num);
            if(gs==0){
                zh=s[i];
               dfs(zh,++gs,++num);
            }
        else  dfs(zh&=s[i],++gs,++num);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    if(m==2){
            long long mx=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,s[i]&s[j]);
            }
        }
        cout<<mx;
        return 0;
    }
    if(m==1){
            long long mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,s[i]);
        }
        cout<<mx;
        return 0;
    }
    if(m==n){
            long long x=s[1];
        for(int i=2;i<=n;i++){
            x&=s[i];
        }
    cout<<x;
    return 0;
    }
    if(m>2000){
        sort(s+1,s+n+1);
        long long mx=s[n];
        for(int i=n-1;i>n-m;i--){
            mx&=s[i];
        }
        cout<<mx;
        return 0;
    }
    dfs(0,0,1);
    cout<<mx;
    return 0;
}

