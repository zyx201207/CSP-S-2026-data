#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,ans;
int a[N];
bool cmp(int a,int b){
    return a>b;
}
void dfs(int k,int step,bool flag,int maxn){
    if(k>n&&step<m) return;
    if(k>n||step>=m){
        ans=max(ans,maxn);
        return;
    }
    if(flag==1){
        if(step==0){
            dfs(k+1,step+1,1,a[k]&a[k]);
            dfs(k+1,step+1,0,a[k]&a[k]);
        }else{
            dfs(k+1,step+1,1,maxn&a[k]);
            dfs(k+1,step+1,0,maxn&a[k]);
        }
        
    }else{
        dfs(k+1,step,1,maxn);
        dfs(k+1,step,0,maxn);
    }
}
bool checkA(){
    for(int i=1;i<=n;++i){
        int x=a[i]+1;
        while(x!=0){
            if(x!=1&&x%2!=0) return false;
            x/=2;
        }
    }
    return true;
}
bool checkB(){
    int x=n;
    while(x!=0){
        if(x!=1&&x%2!=0) return false;
        x/=2;
    }
    for(int i=1;i<=n;++i){
        if(a[i]!=n-i) return false;
    }
    return true;
}
bool checkC(){
    if(a[1]>=4) return false;
    else return true;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1];
        return 0;
    }
    if(m==n||checkA()||checkB()||checkC()){
        int s=a[1];
        for(int i=1;i<=m;++i) s&=a[i];
        cout<<s;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        for(int i=1;i<=n;++i){
            int s;
            if(i!=1) s=a[1];
            else s=a[2];
            for(int j=1;j<=n;++j){
                if(j==i) continue;
                ans=max(ans,s&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    dfs(1,0,1,0);
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}