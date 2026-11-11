#include <bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   cin>>a>>c>>b>>d;
   if(a==b){
       cout<<"1";
   }else{
       cout<<"0000";
       return 0;
   }

   if(c[1]==d[1]&&c[0]==d[0]){
       cout<<"1";
   }else{
       cout<<"000";
       return 0;
    }
    int y=c[2]-'A';
    int z=d[2]-'A';
    int m=max(y,z)-min(y,z);
    if(y>=3&&z>=3){
        cout<<"11";
    }else if(y<=2&&z<=2){
        if(m==1){
            cout<<"11";
        }else{
            cout<<"10";
        }
    }else{
        cout<<"00";
        return 0;
    }
   return 0;
}
