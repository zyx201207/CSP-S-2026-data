#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N=2e5+10;
int Pow[32];
int n,m;
int a[N];
int ans=INT_MAX,q=ans,s=-1;
int mx=-1;
bool f=1;
void dfs(int t,int cnt,int sum){
    if(cnt==m || t==n+1){
        if(cnt==m){
            s=max(s,sum);
        }
        return;
    }
    int ss=sum&a[t];
    dfs(t+1,cnt+1,ss);
    dfs(t+1,cnt,sum);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<=31;i++){
        Pow[i]=pow(2,i)-1;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans&=a[i];
        mx=max(mx,a[i]);
        bool ff=0;
        for(int j=31;j>=0;j--){
            if(Pow[j]==a[i]){ ff=1; break;}
        }
        if(!ff) f=0;
    }
    if(m==n) cout<<ans;
    else if(m==1) cout<<mx;
    else if(m==2){
        int w=-1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                int e=a[i]&a[j];
                w=max(w,e);
            }
        }
        cout<<w;
    }else if(f){
        sort(a+1,a+n+1);
        cout<<a[n-m+1];
    }else{
        dfs(1,0,q);
        cout<<s;
    }
    return 0;
}
