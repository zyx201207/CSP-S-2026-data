#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r1,r2,x1,x2;
    cin>>r1>>r2>>x1>>x2;
    int r=0,x=0;
    for(int i=0;i<r1.size();i++){
        r=r*10+r1[i]-'0';
        x=x*10+x1[i]-'0';
    }
    if(r==x){
        cout<<"1";
        r=0;
        x=0;
        for(int i=0;i<2;i++){
            r=r*10+r2[i]-'0';
            x=x*10+x2[i]-'0';
        }
        if(r==x){
           cout<<"1";
           r=r2[r2.size()-1]-'A';
           x=x2[x2.size()-1]-'A';
           int zw[6]={0};
           zw[r]++;
           zw[x]++;
           int shu=0;
           for(int i=0;i<3;i++){
               if(zw[i]!=0){
                  shu++;
               }
           }
           if(shu==0){
              cout<<"11";
           }
           else if(shu==2){
              cout<<"1";
              if(zw[1]==0){
                cout<<"0";
              }
              else{
                cout<<"1";
              }
           }
           else{
              cout<<"00";
           }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
