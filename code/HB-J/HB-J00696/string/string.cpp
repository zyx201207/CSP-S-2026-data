#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,a,c=0,o=0 ;
string m;
char b;
cin>>n;
cin>>m;
cout<<n;
cout<<m;
for(int i=0;i<n;i++){
    cin>>a>>b;
    while(o<a){
        m[c]=b;
        c++;
        o++;
    }o=0;
}
long long ms=m.size(),s=0;
for(int i=0;i<ms;i++){
    if(m[i]!=m[ms-1-i]){
        s++;
    }m[i]=m[ms-1-i]='0';
}
cout<<s;
return 0;
}
