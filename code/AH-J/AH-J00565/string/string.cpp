#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,a,ans=0;
char c;
cin>>n;
for(int i=1;i<=n;i++){
cin>>a>>c;
while(a--) s += c;
}
for(int i=0,j=s.size()-1;i<j;i++,j--) if(s[i]!=s[j]) ans++;
cout<<ans;
return 0;
}
