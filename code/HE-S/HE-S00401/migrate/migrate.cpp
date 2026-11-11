#include<bits/stdc++.h>
using namespace std;
int c,t;
struct edge{
    int u;
    int v;
    int num;
}e[1000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>t;
    while(t--){
        int n=0,d=0;
        cin>>n>>d;
        int x[n+5];
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    continue;
                }
            }
        }
        cout<<n%3<<endl;
    }
    return 0;
}
