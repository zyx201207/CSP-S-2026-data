#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int MAXN=200005;

int ans=-1;
int n,m;
int a[MAXN];


void dfs(int now,int select,int tans){
    //if(n-now+1+select<m)return;
    if(select>m)return;
    if(select==m){
        ans=max(ans,tans);
        return;
    }
    if(now>n)return;
    if(tans){
        dfs(now+1,select+1,tans&a[now]);
        dfs(now+1,select,tans);
    }else{
        dfs(now+1,select+1,a[now]);
        dfs(now+1,select,0);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    
    int temp=1;
    bool flag=false;
    for(int i=1;i<=20;i++){
        temp*=2;
        if(temp==n){
            flag=true;
            break;
        }
    }

    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1)flag=false;
    }

    if(flag){
        int ans=temp;
        for(int i=1;i<=m;i++)
            temp/=2;
        cout<<temp-1<<'\n';
        return 0;
    }

    if(m==1){
        for(int i=1;i<=n;i++)
            ans=max(ans,a[i]);
        cout<<ans;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans<<'\n';
    return 0;
}