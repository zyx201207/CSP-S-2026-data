#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
string s="";
long long x;
char y;
for(int i=1;i<=n;i++){
    cin>>x>>y;
    for(int i=0;i<x;i++){
        s+=y;
    }
}
int p=s.size();
int ans=0;
for(int i=0;i<p/2;i++){
    if(s[i]!=s[p-i-1]){
        ans++;
    }
}
cout<<ans;
return 0;
}
