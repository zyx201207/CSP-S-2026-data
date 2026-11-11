#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n; cin>>n;
string s="";
for(int i=1;i<=n;i++){
long long t; cin>>t;
char a; cin>>a;
for(long long j=1;j<=t;j++) s=s+a;
}
long long l=0,r=s.size()-1;
long long diff=0;
while(l<=r){
if(s[l]!=s[r]) ++diff;
l++;
r--;
}
cout<<diff;
return 0;
} 
