#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000010],mn=1e18,cnt;
void dfs(long long x,long long y,long long ans){
    if(x==y){
        if(ans<mn){
            mn=ans;
            cnt=1;
        }
        else if(ans==mn){
            cnt++;
        }
        return;
    }
    for(long long i=x+1;i<=y;i++){
        if(a[i]-a[x]>d){
            break;
        }
        dfs(i,y,ans+1);
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }
        bool f=true;
        for(long long i=3;i<=n;i++){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
                f=false;
            }
        }
        if(f){
            long long t=a[2]-a[1];
            long long dis=d/t*2-1;
            if(dis<=1||dis>=n){
                cout<<0<<"\n";
                continue;
            }
            else{
                cout<<n-dis<<"\n";
                continue;
            }
        }
        long long sum=0;
        for(long long i=1;i<n;i++){
            for(long long j=i+1;j<=n;j++){
                mn=1e18;
                cnt=0;
                dfs(i,j,0);
                if(cnt==2){
                    sum++;
                }
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
