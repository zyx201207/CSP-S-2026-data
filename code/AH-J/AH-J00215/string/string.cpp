#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,z;
long long a[50005];
char c[50005];
string s;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i]>>c[i];
s[i]=c[i];
}

if(n%2==0){
    z=n/2;
}
else{
z=(n+1)/2;}
cout<<z;
return 0;
}
