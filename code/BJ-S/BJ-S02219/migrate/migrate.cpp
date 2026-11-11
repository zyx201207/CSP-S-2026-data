#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2E6+10;
ll a[N],d,mi,cnt;
void dfs(int x,ll sum,int y){
    if(x==y){
        if(sum<mi){
            mi=sum;
            cnt=1;
        }
        else if(sum==mi){
            cnt++;
        }
        return;
    }
    for(int i=x+1;i<=y;i++){
        if(a[i]-a[x]>d)break;
        dfs(i,sum+1,y);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==11||c==12){
            int cha=a[2]-a[1];
            int z=d/cha+2;
            cout<<n-z+1<<"\n";
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mi=1e18,cnt=0;
                dfs(i,0,j);
                if(cnt==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
