#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,s[100],m=0,bb=0;
char a;
string b;
s[0]={0};
cin>>n;
for(int i=1;i<=n;i++){

cin>>s[i]>>a;
s[i]+=s[i-1];
for(int j=s[i-1];j<s[i];j++){
b[j]=a;
m++;
}
}
for(int i=0;i<=m;i++){
    if(b[i]==b[i+1]){
        bb=1;
    }else{
    bb=0;
    }
}
if(bb=1){
    cout<<0;
}


return 0;
}



