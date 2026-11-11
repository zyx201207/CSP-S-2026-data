#include<bits/stdc++.h>
using namespace std;
int n,d,t,ans,cnt,mn;
int x[2000010];
void dfs(int i,int c){
    if(i==t){
        if(c==mn)cnt++;
        else if(c<=mn){
            cnt=1;
            mn=c;
        }
        return;
    }
    if(i>t||c>mn)return;
    for(int j=i+1;x[j]-x[i]<=d;j++){
        dfs(j,c+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                t=j;mn=0x3f3f3f3f;cnt=0;
                dfs(i,0);
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
