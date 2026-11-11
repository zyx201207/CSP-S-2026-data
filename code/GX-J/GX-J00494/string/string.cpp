#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
for(int r=0;r<n;r++){
long long s=0,z=0,o=0;
cin>>s>>z;
for(int h=0;h<s;h++){
a[o]=z;
o++;
}
}
int v=a.size(),da=0,pp=a.size();
for(int r=0;r<pp;r++){
if(a[r]!=a[v]){
a[v]=a[r];
da++;
}
v--;
}
cout<<da;
}
