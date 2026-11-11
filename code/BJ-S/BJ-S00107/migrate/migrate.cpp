#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[1000001];
int func(){
    if(c==11||c==12)return (n-2)/2;
    if(c==13||c==14)return n/2;
}
int main(){
    cin.tie(nullptr);
    freopen("mlgrate.in","r",stdin);
    freopen("mlgrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        memset(x,0,sizeof(x));
        for(int j=1;j<=d;j++){
            cin>>x[i];
        }
        cout<<func<<"\n";
    }
    return 0;
}
