#include<bits/stdc++.h>
using namespace std;
int main(){
string a,b,c,d;
ifstream fin("travel.in");
ofstream fout("travel.out");
cin>>a>>b>>c>>d;
if(a==c){
fout<<"1";
  if(b[1]==d[1]&&b[2]==d[2]){
    fout<<"1";
    if(b[3]=='F'&&d[3]=='D'||b[3]=='D'&&d[3]=='F'||b[3]=='A'&&(d[3]=='B'||d[3]=='C')||b[3]=='B'&&(d[3]=='A'||d[3]=='C')||b[3]=='C'&&(d[3]=='B'||d[3]=='A')||d[3]=='A'&&(b[3]=='B'||b[3]=='C')||d[3]=='B'&&(b[3]=='A'||b[3]=='C')||d[3]=='C'&&(b[3]=='B'||b[3]=='A')){
      fout<<"1";
      if(b[3]=='F'&&d[3]=='D'||b[3]=='D'&&d[3]=='F'||b[3]=='A'&&d[3]=='B'||b[3]=='C'&&(d[3]=='A'||d[3]=='C')||b[3]=='C'&&d[3]=='B'||d[3]=='A'&&b[3]=='B'||d[3]=='B'&&(b[3]=='A'||b[3]=='C')||d[3]=='C'&&b[3]=='B'){
        fout<<"1";
        return 0;
      }else{
      fout<<"0";
      return 0;
      }
      }
    else{
    fout<<"00";
    return 0;
    }
   }
   else{
   fout<<"000";
   return 0;
   }
   }
   else{
   fout<<"0000";
   return 0;
   }
return 0;
}

