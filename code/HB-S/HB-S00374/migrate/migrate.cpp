#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n,d,x[2200000],ans=0,tmpans;
void dfs(int s,int e){
    if(s==e){
        tmpans++;
        return ;
    }
    for(int i=s;i<=e;i++)if(x[e]-x[i]<=d)dfs(i,e);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        bool f=1;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=2;i<=n;i++)if(x[i]-x[i-1]!=x[i-1]-x[i-2])f=0;
        if(n<3){
            cout<<0;
            continue;
        }
        if(f&&d>=x[3]-x[1]&&n>=3){
            cout<<n-3<<endl;
            continue;
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                tmpans=0;
                dfs(i,j);
                ans+=tmpans==2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
