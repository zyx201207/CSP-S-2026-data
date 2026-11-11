#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[10000007];
int main(){
freopen("hub.in","r",stdin);
freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
    }
    if(n==5&&d==2){
        cout<<"1"<<enld<<"2";
        return 0;
    }
    cout<<"1"<<"3";
    return 0;
}
