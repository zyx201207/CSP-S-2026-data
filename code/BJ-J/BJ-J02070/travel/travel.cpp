#include<bits/stdc++.h>
using namespace std;
int main(){
freopen ("travel","r",stdin);
freopen ("travel","w",stdout);
int s[4];
int a[1005];
int b[1005];
int c1,s1,c2,s2,o1,o2,f1,f2,g1,g2,h1,h2,j1,j2,k1,k2;
cin>>c1>>c2>>s1>>s2>>o1>>o2>>f1>>f2>>g1>>g2>>h1>>h2>>j1>>j2>>k1>>k2;
int n;
for(int i=1 ;i<=n;i++){
if(c1==c2){
cout<<"1";
}else{
cout<<" 0";
}if(s1==s2){
cout<<"1 ";
}else cout<<" 0";
if(c1==c2&&s1==s2){
cout<<"11";
}else if(c1==c2&&s1!=s2){
cout<<"10";
}else if(c1!=c2&&s1==s2){
cout<<"01 ";
}
return 0;
}
}
