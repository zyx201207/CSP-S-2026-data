#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int cl(int a,int b){
	return (a+b-1)/b;
}
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
string s="";
int ans=0,R,num;
char w;
cin>>R;
for(int i=1;i<=R;++i){
	cin>>num>>w;
	for(int j=1;j<=num;++j)
		s+=w;
}
for(int i=0;i<cl(s.size(),2);++i){
	if(s[i]!=s[s.size()-1-i])
	++ans;
}
cout<<ans;
return 0;
}
