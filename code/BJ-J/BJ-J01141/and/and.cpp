#include<bits/stdc++.h>
using namespace std;
int a[200010][35],n,m,x,cnt,ans;
bool lose[200010],flag[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=0;j<=30;j++) a[i][j]=(x>>j)&1;
    }
    for(int j=30;j>=0;j--){
        memset(flag,false,sizeof(flag));cnt=0;
        for(int i=1;i<=n;i++){
            if(!lose[i]&&a[i][j]) cnt++,flag[i]=true;
        }
        if(cnt>=m){
            ans+=(1<<j);
            for(int i=1;i<=n;i++) if(!flag[i]) lose[i]=true;
        }
    }
    cout<<ans;
    return 0;
}