#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.cpp","r",stdin);
	freopen("travel.cpp","w",stdout);
int i=1,b[11];
char a[11];
for(i=1;i<11;i++){
cin>>a[i];
}
for(i=1;i<=4;i++){
b[i]=a[i]-'0';
}
for(i=6;i<=9;i++){
b[i]=a[i]-'0';
}
b[5]=a[5]-'A';
b[10]=a[10]-'A';
if(b[5]<b[10]){
i=b[5];
b[5]=b[10];
b[10]=i;
}
if(b[1]!=b[6])
cout<<"0000";
else
if(b[2]!=b[7])
cout<<"0000";
else
if(b[3]!=b[8])
cout<<"1000";
else
if(b[4]!=b[9])
cout<<"1000";
else
if(b[10]=2)
cout<<"1100";
else
cout<<"1110";
return 0;
}
