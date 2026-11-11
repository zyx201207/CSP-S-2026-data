#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c,s,c1,s1;
cin>>c>>s>>c1>>s1;
if(c==c1){
cout<<1;
}else{
cout<<0;
}if(s[1]==s1[1]){
    cout<<1;
}else{
cout<<0;
}
if(s[2]==s1[2]){
  cout<<1;
}else{cout<<0;
};
if(s[3]==s1[3]+1||s[3]==s1[3]+1){
    cout<<1;
}else{
cout<<0;
};
return 0;
}
