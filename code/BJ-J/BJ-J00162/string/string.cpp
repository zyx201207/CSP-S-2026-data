#include<bits/stdc++.h>
using namespace std;
int n,a;
long long ss;
char c;
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
cin>>a>>c;
while(a--)   s+=c;
}
for(int i=0;i<n/2;i++){
if(a[i]!=a[n-i-1])ss++;
}
cout<<ss;
fclose(stdin);
fclose(stdout);
return 0;
}