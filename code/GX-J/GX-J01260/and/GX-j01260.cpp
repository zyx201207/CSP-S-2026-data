#include<bits/stdc++.h>
using namespace std
int mine(){
freopen("travel.in"."r".std);
freopen("travel.out"."w".std);
int b,n;
cin>>b>>n;
string a[4];
string s[4];
for(int i=i;i<3;i++){
    cin>>s[i];
}
for(int i=i;i<3;i++){
    cin>>a[i];
}
int h[5];
for(int i=1;i<5;i++){
     h[i]==0   
    cin>>h[i];
}
if(b>1&&b<17&&n>1&&n<16) else brake;
if(b==n){
    h[1]=1;
}else cout<<"0000";
for(int i=i;i<3;i++){
    if(a[i]==s[i]){
        h[i+1]==1;
    }else h[i+1]==0;
}
string d;
cin>>d;
string f;
cin>>f;
 if(f!=d){
    h[5]==1;
 }
for(int i=1;i<5;i++){
    cout<<h[i];
}

return 0;
}
