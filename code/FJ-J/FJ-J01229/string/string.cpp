10#include<bits/stdc++.h>
using namespace std;
int a,ans=0;
string b,s;
int main(){
int n;

freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a>>b;	
	while(a--)
	s+=b;
	
}
cout<<s;
for(int i=0;i<s.size()/2;i++){
	if(s[i]!=s[s.size()-i-1]) ans++;
}
cout<<ans;
return 0;
}
