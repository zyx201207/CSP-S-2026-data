#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000500],ans,nn,cnt,ds;
void dfs(int fym,int s){
    if(s>nn) return;
    if(fym==ds){
        cnt++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(i==fym) continue;
        if(abs(x[fym]-x[i])<=d){
             dfs(i,s+1);
        }
    }
    return;
}
bool check(int x1,int  x2){
    nn=0; int xx=0; cnt=0;
    for(int i=x1+1;i<=x2;i++){
        if(xx+x[i]-x[i-1]>d){
            nn++; xx=x[i]-x[i-1];
        }
        else xx+=x[i]-x[i-1];
    }
    nn++; ds=x2;
    dfs(x1,0);
    if(cnt==2) return true;
    return false;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d; ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        sort(x+1,x+n+1);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(check(i,j)) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
