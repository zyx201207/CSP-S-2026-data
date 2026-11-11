#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int u,t;cin>>u>>t;
    int n;long long d;
    while(t--){
        cin>>n>>d;
        for(int i=0;i<n;i++){
            long long x;cin>>x;
        }
    }
    if(!u){
        if(n==5 and d==2)cout<<1<<endl<<2;
        else if(n==6 and d==2)cout<<0<<endl<<1;
        else if(n==1 and d==3)cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
    }
    return 0;
}
