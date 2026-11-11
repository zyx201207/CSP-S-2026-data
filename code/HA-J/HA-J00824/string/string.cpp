#include<bits/stdc++.h>
using namespace std;
long long n,k,t=1;
char k2;
long long x,y,ans=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
char s1[n+1];
for(int i=1;i<=n;i++){
	cin>>k;
	cin>>k2;
	for(int j=1;j<=k;j++){
		s1[t]=k2;
		t++;}
}
x=1;
y=t-1;
for(int i=1;i<=t/2;i++){
if(s1[x]!=s1[y]){
ans++;
}
x++;
y--;
}
cout<<ans<<endl;
	return 0;
}
