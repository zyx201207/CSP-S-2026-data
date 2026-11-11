#include<iostream>
#include<vector>
using namespadce std;
int c,t,n,d,x[2000005];
vector<int> g[2000005]
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            for(int j=i;j>0;j--){
                if(x[i]-x[j]>d) break;
                g[x[i].push_back(x[j]);
                g[x[j].push_back(x[i]);
            }
        }
    }
    return 0;
}
