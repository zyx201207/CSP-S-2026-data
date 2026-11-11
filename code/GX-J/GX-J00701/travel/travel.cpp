#include <bits/stdc++.h>
using namespace std;

int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   string a,b,c,d;
   cin>>a>>b>>c>>d;
   if(int(a[0])+int(a[1])==int(c[0])+int(c[1])){
       cout<<'1';
   }
   else{
        cout<<"0000";
       return 0;
   }
   if(int(b[0])+int(b[1])==int(d[0])+int(d[1])){
        cout<<'1';
   }
   else{
        cout<<'0';
   }
   if(b[2]=='A'&&d[2]=='B'){
        cout<<'1';
   }
   else if(b[2]=='A'&&d[2]=='C'){
        cout<<'1';
   }
   else if(b[2]=='B'&&d[2]=='A'){
        cout<<'1';
   }
   else if(b[2]=='B'&&d[2]=='C'){
        cout<<'1';
   }
   else if(b[2]=='C'&&d[2]=='A'){
        cout<<'1';
   }
   else if(b[2]=='C'&&d[2]=='A'){
        cout<<'1';
   }
   else if(b[2]=='C'&&d[2]=='B'){
        cout<<'1';
   }
   else{
        cout<<'0';
   }
   if(b[2]=='A'&&d[2]=='B'){
        cout<<'1';
   }
   else if(b[2]=='B'&&d[2]=='A'){
        cout<<'1';
   }
   else if(b[2]=='B'&&d[2]=='C'){
        cout<<'1';
   }
   else if(b[2]=='C'&&d[2]=='B'){
        cout<<'1';
   }
   else{
        cout<<'0';
   }
return 0;
}
