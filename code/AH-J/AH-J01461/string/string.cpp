#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int a,c=0,d=0,n,m=0;
string s;
char b;
cin>>n;
for(int i=1;i<=n;i++){
cin>>a>>b;
for(int j=1;j<=a;j++){
	c++;
	s[c]=b;
}
m+=a;
}
for(int i=1;i<=m/2;i++){
    if(s[i]!=s[m+1-i]){
		d++;
	}
}
cout<<d;
return 0;
}
