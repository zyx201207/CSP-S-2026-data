#include<bits/stdc++.h>
using namespace std;
int n,a[200001],s=0,x=0;
string b[200001],c[199999999];
int main(){
//freopen("string.in",'r',stdin);
//freopen("string.out",'w',stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>b[i];
	for(int j=x+1;j<=x+a[i];j++){
		c[j]=b[i];
	}
	x+=a[i];
}
if(x%2!=0){
for(int i=1;i<=x/2+1;i++){
	if(c[i]!=c[x+1-i]){
		s++;
	}
}
}
else{
	for(int i=1;i<=x/2;i++){
	if(c[i]!=c[x+1-i]){
		s++;
	}
}
}

	cout<<s;

return 0;
}
