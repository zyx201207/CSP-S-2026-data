#include<bits/stdc++.h>
using namespace std;
int main(){
        freopen("travel.in","r",stdin);
        freopen("travel.out","w",stdout);
         string c1_,c2_,s1_,s2_;
       cin >> c1_ >> s1_ >> c2_ >> s2_;
       bool f = true;
        for(int i = 0;i < c1_.length();i++){
                      if(c1_[i] != c2_[i]){
                             f = false;
                      }
         } if(f == false){
                   cout << "0000";
                    return 0;
          }else cout << "1";
         for(int i = 0;i < 2;i++){
                   if(s1_[i]!=s2_[i]&&i < 2) {
                              cout << "000";
                              return 0;
                    }
         }cout << "1";
        if(s1_[2] > s2_[2]){
                 int z = s1_[2] - s2_[2];
                 if(z == 1&&s1_[2]!= 'D'){
                         cout <<  "11";
                          return 0;
                 }else if(z <= 2&&s1_[2]!= 'D'){
                          cout << "10";
                          return 0;
                 }else cout << "00";
         }else if(s2_[2] > s1_[2]){
                 int z = s2_[2] - s1_[2];
                 if(z == 1&&s2_[2]!= 'D'){
                         cout <<  "11";
                          return 0;
                 }else if(z <= 2&&s2_[2]!= 'D'){
                          cout << "10";
                          return 0;
                 }else cout << "00";
         }return 0;
}