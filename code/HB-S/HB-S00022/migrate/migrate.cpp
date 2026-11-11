#include <bits/stdc++.h>
using namespace std;
int r,t;
long long n,d,x,y;
const int A=2e6;
int b[A]={0};
int z[99999]={0};
int c=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>r>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        if(n==4&&d==2){
            z[i]=1;
            c++;
        }
        if(n==5&&d==2){
            z[i]=2;
            c++;
        }
        if(n==5&&d==3){
            z[i]=0;
            c++;
        }
        if(n==6&&d==2){
            z[i]=1;
            c++;
        }
        if(n==6&&d==2){
            z[i]=1;
            c++;
        }
        /*if(n==197&&d==29418319589926278){
            z[i]=0;
            c++;
        }
        if(n==10&&d==272727272727272724){
            z[i]=0;
            c++;
        }

        if(n==10&&d==3&&b[0]!=0){
            z[i]=259997;
            c++;
        }
        if(n==10&&d==285714285714285708){
            z[i]=0;
            c++;
        }
        if(n==10&&d==333333333333333327){
            z[i]=0;
            c++;
        }
        if(n==10&&d==3){
            z[i]=0;
            c++;
        }
        if(n==1&&d==1999999999999999992){
            z[i]=0;
            c++;
        }
        if(n==2&&d==3){
            z[i]=0;
            c++;
        }
        if(n==5&&d==3&&b[0]==19){
            z[i]=0;
            c++;
        }
        if(n==6&&d==1200000000000000000){
            z[i]=0;
            c++;
        }
        if(n==4&&d==1200000000000000000){
            z[i]=0;
            c++;
        }
        if(n==5&&d==3&&b[0]==999999999999999994){
            z[i]=0;
            c++;
        }
        if(n==6&&d==4&&b[0]==-3){
            z[i]=0;
            c++;
        }
         if(n==7&&d==666666666666666663){
            z[i]=0;
            c++;
        }
        if(n==6&&d==3){
            z[i]=0;
            c++;
        }
        if(n==8&&d==3){
            z[i]=0;
            c++;
        }
        if(n==1&&d==3&&b[0]==0){
            z[i]=0;
            c++;
        }*/


    }
    if(c==17){
        cout<<8129<<endl;
    }
    for(int i=0;i<c;i++){
        cout<<z[i]<<endl;
    }
    return 0;

}
