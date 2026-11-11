#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
int a,s,z,x,q=0;
char d,f;
cin>>a>>s>>d>>z>>x>>f;
if(a==z){
    cout<<1; q++;
}else{
cout<<0;
}
if(s==x && q==1){
    cout<<1;q++;
}else{
cout<<0;
}


if(max(d,f)=='D' or max(d,f)=='F' && min(d,f)!='D'){

    cout<<0;
}else if(q!=2){
cout<<0;
}else{
cout<<1;q++;}
int w=0;

if(d+1==f or f+1==d){

    if(q==3){
w++;
    cout<<1;}
}else{
cout<<0;
}

if(w==0){
    cout<<0;
}


return 0;
freopen("travel.out","w",stdout);
}
