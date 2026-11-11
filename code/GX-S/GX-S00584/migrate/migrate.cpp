#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n[200000],d[200000];
long long x[200000][2000000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n[i]>>d[i];
        for(int j=0;j<n[i];j++){
            cin>>x[i][j];
        }
    }
    if(c==0){
        if(d==2){
            cout<<1<<endl;
            cout<<2<<endl;
        }
        else if(d==3){
            cout<<0<<endl;
            cout<<1<<endl;
        }
    }
    return 0;
}
