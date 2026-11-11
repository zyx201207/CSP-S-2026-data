#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005][35],maxn,ans[35],ansl;
bool vis[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    m=n-m;
    for(int i=1,x;i<=n;i++){
        cin>>x;
        ll cnt=0;
        while(true){
            a[i][++cnt]=x%2;
            x/=2;
            if(x==0)break;
        }
        maxn=max(maxn,cnt);
    }
    for(int i=1;i<=n;i++){
        reverse(a[i]+1,a[i]+maxn+1);
    }
    for(int i=1;i<=maxn;i++){
        ll cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]==0&&!vis[j])cnt++;
        }
        if(cnt<=m){
            m-=cnt;
            ans[i]=1;
            for(int j=1;j<=n;j++){
                if(a[j][i]==0)vis[j]=1;
            }
        }
    }
    ll cnt=0;
    for(int i=maxn;i>=1;i--){
        ansl+=ans[i]*pow(2,cnt);
        cnt++;
    }
    cout<<ansl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

