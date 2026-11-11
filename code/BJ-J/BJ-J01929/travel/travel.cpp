#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   cin>>c1>>s1>>c2>>s2;
   if(c1==c2) cout<<1;
   else {
        cout<<"0000";
        return 0;
   }
   string a1=s1.substr(0,2);
   string a2=s2.substr(0,2);
  // cout<<"**"<<a1<<" "<<a2<<endl;
   if(a1==a2) cout<<1;
   else{
        cout<<"000";
        return 0;
   }
   int b1=s1[2]-'A'+1;
   int b2=s2[2]-'A'+1;
   //cout<<"&&"<<b1<<" "<<b2<<endl;
   if(1<=b1&&b1<=3&&1<=b2&&b2<=3){
        cout<<1;
   }
   else if(4<=b1&&b1<=5&&4<=b2&&b2<=5){
        cout<<1;
       // cout<<"#";
   }
   else{
        cout<<"00";
        return 0;
   }


   if(b1==b2+1||b1==b2-1) cout<<1;
   else cout<<0;
   return 0;
}
