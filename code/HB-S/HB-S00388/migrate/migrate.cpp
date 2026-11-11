#include<bits/stdc++.h>
using namespace std;
//migrate

int c,t;

void solve(){
    int n,d;
    int x[200005]={0};
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    if(d==1){
        cout<<0<<"\n";
        return;
    }
    int c=0;
    for(int i=1;i<=n-3;i++){
        if(x[i+3]-x[i]>d&&((x[i+1]-x[i]<=d&&x[i+3]-x[i+1]<=d&&x[i+2]-x[i]<=d&&x[i+3]-x[i+2]<=d)))c++;
    }
    cout<<c<<"\n";
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>c>>t;
    for(int i=1;i<=t;i++){
            solve();
    }

    return 0;
}
