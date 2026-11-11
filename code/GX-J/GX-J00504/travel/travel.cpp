#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
char x,r;
int a,b,c,d;
cin>>a>>c>>x>>b>>d>>r;
if(a!=b){
cout<<"0000";
return 0;
}
else{
    cout<<"1";
}
if(c!=d){
    cout<<"000";
    return 0;
}
else{
    cout<<"1";
}

 if(x=='A'||x=='B'||x=='C'&&r=='A'||r=='B'||r=='C'){
    cout<<"1";
}

else if(x=='D'||x=='F'&&r=='D'||r=='F'){
    cout<<"1";
}
else if(x=='A'||x=='B'||x=='C'&&r=='D'||r=='F'){
    cout<<"00";
    return 0;
}
else if(x=='D'||x=='F'&&r=='A'||r=='B'||r=='C'){
    cout<<"00";
    return 0;
}
else{
    cout<<"00";
    return 0;
}
if(x=='A'&&r=='B'||x=='B'&&r=='C'||x=='B'&&r=='A'||x=='D'&&r=='F'||x=='F'&&r=='D'){
    cout<<"1";
}
else{
    cout<<"0";
}


return 0;
}
