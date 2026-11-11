#include <bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,f,fini;
int n;
ll d,a[2000005],ans,mi=1e18,cnt;
void dfs(int x,ll l){
    if(x==fini){
        if(l<mi){
            mi=l;
            ans=1;
        }else{
            if(l==mi){
                ans++;
            }
        }
        return;
    }
    for(int i=x+1;i<=fini;i++){
        if(a[i]-a[x]>d)break;
        dfs(i,l+1);
    }
}
void check(int x,int y){
    fini=y;
    mi=1e18;
    ans=0;
    dfs(x,0);
    if(ans==2)f=1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                f=0;
                check(i,j);
                if(f==1){
                    cnt++;
                    //cout<<i<<' '<<j<<endl;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
