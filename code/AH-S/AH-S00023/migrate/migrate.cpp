#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c,t,d,x[10005][10005],a=0;
    cin>>c;
    if(c==0){
        freopen("migrate.in","r",stdin);
        freopen("migrate.out","w",stdout);
    }else if(c==1){
        freopen("migrate1.in","r",stdin);
        freopen("migrate1.out","w",stdout);
    }else if(c==2){
        freopen("migrate2.in","r",stdin);
        freopen("migrate2.out","w",stdout);
    }else if(c==3){
        freopen("migrate3.in","r",stdin);
        freopen("migrate3.out","w",stdout);
    }else if(c==4){
        freopen("migrate4.in","r",stdin);
        freopen("migrate4.out","w",stdout);
    }else if(c==5){
        freopen("migrate5.in","r",stdin);
        freopen("migrate5.out","w",stdout);
    }else if(c==6){
        freopen("migrate6.in","r",stdin);
        freopen("migrate6.out","w",stdout);
    }
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[i][j];
        }
    }
    for(int i=1;i<=t;i++){
            a=0;
        for(int j=1;j<=n;j++){
            if(x[i][j+2]-x[i][j]==2){
                a++;
            }
        }
    cout<<a<<endl;
    }
    return 0;
}
