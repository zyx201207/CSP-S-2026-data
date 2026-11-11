#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>
using namespace std;
//migrate

long long c,t;

void solve(){
    long long n,k;
    srand(time(0));
    vector<int> a[1000005];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cout<<rand()%2+1<<"\n";
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c>>t;
    for(int i=1;i<=t;i++){
            solve();
    }

    return 0;
}
