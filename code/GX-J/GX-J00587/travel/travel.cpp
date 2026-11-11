#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="0000";
void f(string &a,string &b){
   if(a=="A"&&b=="B"){
        ans="1111";
        return;
   }
   if(a=="A"&&b=="C"){
        ans="1110";
        return;
   }
   if(a=="B"&&b=="A"){
        ans="1111";
        return;
   }
   if(a=="B"&&b=="C"){
        ans="1111";
        return;
   }
   if(a=="C"&&b=="B"){
        ans="1111";
        return;
   }
   if(a=="C"&&b=="A"){
    ans="1110";
    return;
   }
   if(a=="D"&&b=="F"){
    ans="1111";
    return;
   }
   if(a=="F"&&b=="D"){
    ans="1111";
    return;
   }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2&&(c1!="01"&&c2!="01")){
        ans="1000";
        string r_row,x_row,r_seat,x_seat;
        r_row=s1.substr(0,2);
        x_row=s2.substr(0,2);
        r_seat=s1[2];
        x_seat=s2[2];
        if(r_row==x_row){
            ans="1100";
            f(r_seat,x_seat);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
