#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string s;
char n[1006];
int cnt1=0,cnt2=0;

for(int i=1;i<=4;i++){
cin>>s[i];
}
if(s[0]==s[2]){
cout<<'1';
}
else  cout<<'0';
if(s[1]<='9'&&s[1]>='0'){
     cnt1+=s[1];

}
if(s[3]<='9'&&s[3]>='0'){
      cnt2+=s[3];

}
if(cnt1==cnt2){
cout<<'1';
}else cout<<'0';
if(s[1]>='A'&&s[1]<='F'){
     n[0]=s[1];

}
if(s[3]>='A'&&s[3]<='F'){
     n[1]=s[3];

}
if(n[0]==n[1]||!n[0]==n[1]- char(1) || ! (  n[0]==n[1]+char(1)  )       ){
   cout<<'0';

}else if(n[0]==n[1]- char(1) ||  n[0]==n[1]+char(1)           ) {

    cout<<'1';


}
return 0;

}


