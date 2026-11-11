#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
char n[10],m[10];
int a,b;
cin>>a>>n>>b>>m;
if(a==b){
    cout<<1;
   if(n[0]==m[0]&&n[1]==m[1]){
    cout<<1;
    if(n[2]=='C'&&m[2]=='D'||n[2]=='D'&&m[2]=='C'){
        cout<<"00";
    }else{
    cout<<1;
    if(n[2]-1==m[2]||m[2]-1==n[2]){
        cout<<1;
    } else{
    cout<<0;
    }
    }
   } else{
   cout<<"000";
   }
} else{
cout<<"0000";
}
return 0;
}
