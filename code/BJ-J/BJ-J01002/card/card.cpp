#include<bits/stdc++.h>
#define N 200010
#define int long long
using namespace std;

int n,m;
int a[N],cnt[N];

void solve(int st){
    int p[N*2]={};
    for(int i=st;i<=n;i++){
        if(p[a[i]]==0){
            p[a[i]]=i-st+1;
        }
        else{
            for(int j=1;j<=m;j++){
                if(p[j]>p[a[i]]) p[j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(p[i]!=0) cnt[i]++;
    }
}

void solve_pian(int st){
    a[st-1]=0;
    bool p[2*N]={};
    for(int i=st;i<=n;i++){
        p[a[i]]=true;
    }
    for(int i=1;i<=m;i++){
        if(p[i]==true) cnt[i]++;
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>=500&&m>=200){
        for(int i=1;i<=n;i++){
            solve_pian(i);
        }
        for(int i=1;i<=m;i++){
            cout<<cnt[i]<<' ';
        }
    }
    for(int i=1;i<=n;i++){
        solve(i);
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}