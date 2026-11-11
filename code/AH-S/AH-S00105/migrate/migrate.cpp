#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,t,n,d;
ll x[200005];

void dfs(int a,int b){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;++i)
            cin>>x[i];
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i!=j)
                    dfs(i,j);
    }
    return 0;
}

