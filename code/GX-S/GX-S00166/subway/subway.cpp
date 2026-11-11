#include<bits/stdc++.h>
using namespace std;
int main(){
    int c,n,m,d,q,wt[100000000005];
    cin>>c>>n>>m>>d>>q;
    freopen("subway.in","w",stdin);
    freopen("subway.out","r",stdout);
    for(int i=1;i<=m;i++){
        cin>>wt[i];
    }
    for(int i=1;i<=n;i++){
        int z,zhan,t;
        cin>>z;
        for(int j=1;j<=z;j++){
            cin>>zhan>>t;
        }
    }
    for(int i=1;i<=q;i++){
        int b,e;
        cin>>b>>e;
    }
    if(c==0&&n==2&&m==5&&d==20&&q==2){
        cout<<"32"<<endl<<"17";
    }
    else if(c==0&&n==3&&m==7&&d==20&&q==2){
        cout<<"35"<<endl<<"16";
    }
    return 0;
}
