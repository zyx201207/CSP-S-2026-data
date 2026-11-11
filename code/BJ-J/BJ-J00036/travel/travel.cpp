#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,arr,brr;
    cin>>a>>arr>>b>>brr;
    if(a==b){
    cout<<"1";
    if(arr[0]==brr[0]&&arr[1]==brr[1]){
     cout<<"1";
     if((arr[2]<='C'&& brr[2]<='C')||(arr[2]>'C'&&brr[2]>='C')){
     cout<<"1";
     if(arr[2]==brr[2]+1||arr[2]==brr[2]-1){
       cout<<'1';
      }else cout<<'0';

     }else cout<<"00";
    }else cout<<"000";
   }else cout<<"0000";
   return 0;
}