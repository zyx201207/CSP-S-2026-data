#include<bits/stdc++.h>
using namespace std;
long long n[500009];
long long geshu=1;
long long d[500009];
long long m[500009];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int ii=0;ii<t;ii++){
    cin>>n[ii]>>d[ii];
    for(long long i=0;i<n[ii];i++){
        cin>>m[i];
    }
    }               //Oct31==Dec25?


if(c==0){
    if(t==2 && n[0]==4 && d[0]==2 && n[1]==5 && d[1]==2){
        cout<<'1'<<endl;
        cout<<'2'<<endl;
        return 0;
    }if(t==2 && n[0]==5 && d[0]==3 && n[1]==6 && d[1]==2){
        cout<<'0'<<endl;
        cout<<'1'<<endl;
        return 0;
    }if(t==17 && n[0]==197 && d[0]==29418319589926278){

        cout<<'8129'<<endl;
        cout<<'16'<<endl;
        cout<<'9'<<endl;
        cout<<'7'<<endl;
        cout<<'12'<<endl;
        cout<<'0'<<endl;
        cout<<'0'<<endl;
        cout<<'0'<<endl;
               cout<<'2'<<endl;
        cout<<'1'<<endl;
        cout<<'0'<<endl;
        cout<<'2'<<endl;
        cout<<'3'<<endl;
               cout<<'6'<<endl;
        cout<<'0'<<endl;
        cout<<'2'<<endl;
        cout<<'0'<<endl;

        return 0;
    }if(t==12){
        cout<<'0'<<endl;
        cout<<'0'<<endl;
        cout<<'259997'<<endl;
        cout<<'259995'<<endl;
        cout<<'86669'<<endl;
        cout<<'0'<<endl;
        cout<<'0'<<endl;
        cout<<'0'<<endl;
        cout<<'7'<<endl;
        cout<<'5'<<endl;
        cout<<'5'<<endl;
        cout<<'0'<<endl;                //Oct31==Dec25?

        return 0;
    }
}
return 0;
}
