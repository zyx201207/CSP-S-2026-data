#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
//I love Luogu!
int a[500001];
int lst[300001];
int ans[300001];
int ml[500001];
int mv[500001];
vector<int> sol[500001];
vector<int> operator+(vector<int> v,int x){
    v.push_back(x);
    return v;
}
inline int read(){
    char c='/';
    int ans=0;
    while(!isdigit(c)) c=getchar_unlocked();
    while(isdigit(c)){
        ans=ans*10+c-'0';
        c=getchar_unlocked();
    }
    return ans;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[n-i+1]=read();
        ml[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(lst[a[i]]==0){
            sol[i]=sol[i-1]+a[i];
            lst[a[i]]=i;
            mv[i]=i-1;
        }
        else{
            sol[i]=sol[lst[a[i]]-1]+a[i];
            mv[i]=lst[a[i]]-1;
        }
    }
    for(int i=n;i>=1;i--){
        ml[mv[i]]+=ml[i];
        if(mv[i]!=0) ans[a[i]]+=ml[i];
        else{
            for(int j=0;j<sol[i].size();j++){
                ans[sol[i][j]]+=ml[i];
            }
        }
    }
    for(int i=1;i<=m;i++){
        printf("%lld ",ans[i]);
    }
    return 0;
}
