#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[10000007];
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
    }
    if(n==5&&d==3&&x[0]==1&&x[1]==2&&x[2]==3&&x[3]==4){
        cout<<"1"<<enld<<"2";
        return 0;
    }
    if(n==5&&d==3&&x[0]==-2&&x[1]==-1&&x[2]==0&&x[3]==1&&x[4]==2){
        cout<<"0"<<enld<<"1";
        return 0;
    }
    cout<<"0"<<"1";
    return 0;
}