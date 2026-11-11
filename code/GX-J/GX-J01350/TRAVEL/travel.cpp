#include<bits/stdc++.h>
using namespace std;







int main(){
  freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
int n[3],a1[100],b1[100];
string a,b;
int s=0;
cin>>n[1]>>a;
cin>>n[2]>>b;
for(int i=0;i<=1;i++){
    a1[i]=a[i]-'0';
    b1[i]=b[i]-'0';
}
while(s=1){
if(a[2]=='A'&&b[2]=='B'){
    s=1;
    break;
}else if(a[2]=='A'&&b[2]=='C'){
s=1;
break;
}else{
s=0;
}

if(a[2]=='B'&&b[2]=='C'){
    s=1;
    break;
}else if(a[2]=='B'&&b[2]=='A'){
    s=1;
    break;
}else{
s=0;
}

if(a[2]=='C'&&b[2]=='A'){
    s=1;
    break;
}else if(a[2]=='C'&&b[2]=='B'){
    s=1;
    break;
}else{
s=0;
}

if(a[2]=='D'&&b[2]=='F'){
    s=1;
    break;
}else if(a[2]=='F'&&b[2]=='D'){
s=1;
break;
}
break;
}





if(n[1]==n[2]){
    cout<<1;
    if(a1[0]==b1[0]&&a1[1]==b1[1]){
        cout<<1;
        if(s==1){
            cout<<1;
        if(a[2]==b[2]+1||a[2]==b[2]-1){
    cout<<1;
}else{
cout<<0;
}

        }
        else{
        cout<<0;
        cout<<0;
        return 0;
        }
    }else{
    cout<<0;
    cout<<0;
    cout<<0;
    return 0;
    }
}
else{
for(int i=1;i<=4;i++){
    cout<<0;
}
return 0;
}

fclose(stdin);
fclose(stdout);





return 0;
}
