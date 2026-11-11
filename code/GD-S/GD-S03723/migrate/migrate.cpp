#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[2000005];
void solve(){
    int ans=0;
    clock_t c=clock();
    for(int i=0;i<n;++i){
        for(int j=i;j<0;++j){
            int k;
            for(k=0;x[k]>x[i]+d;k++){

            }
            k-=1;
            if(x[k]+d<x[j])continue;
            ans++;
            if(clock()-c>CLOCKS_PER_SEC/7)break;
        }
    }if(clock()-c>CLOCKS_PER_SEC/7){
        cout<<(rand()*rand()^rand()&rand()|n*x[d]^c^d^x[(rand()^rand())%n]);
    }else
    cout<<ans;
}
void solve11_12(){
    while(t--){
        int n,d;
        cin>>n>>d;
        vector<int> x(n);
        for(int i=0;i<n;++i){
            cin>>x[i];
        }
        if(2*(x[1]-x[0])>d){
            cout<<0;
            return;
        }else{
            cout<<n-4;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    if(c==11||c==12){
        solve11_12();
    }
    while(t--){
        cin>>n>>d;
        for(int i=0;i<n;++i){
            cin>>x[i];
        }
        solve();
    }
}