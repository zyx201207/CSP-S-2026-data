#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int c,t;
int n;
ll d,x[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin>>c>>t;
    //if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            if(n==1){
                cout<<0<<"\n";
                continue;
            }
            ll w=x[2]-x[1];
            w=d/w;
            w=2*w-1;
            if(n>w&&d/(x[2]-x[1])>1) cout<<n-w<<"\n";
            else cout<<0<<"\n";
        }
   // }
    return 0;
}
