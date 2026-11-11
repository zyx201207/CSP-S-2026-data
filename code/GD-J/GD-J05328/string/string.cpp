#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
int n,sum=0,p;
cin>>n;
int a[n+1],s=0,h=0;
string b[n+1];
for(int i=1;i<=n;i++){
	cin>>a[i];
	sum+=a[i];
	cin>>b[i];
	for(int j=1;j<=a[i];j++){
		s*=10;
		s+='b[i]';
	}
}
for(int i=n;i<=1;i--){

	for(int j=1;j<=a[i];j++){
		h*=10;
		h+='b[i]';
	}
}
if(s==h){
	cout<<"0";
	return 0;
}else{
	for(int i=0;i<=sum;i++){
		char c=s%10;
		char d=h%10;
		s=s/10;
		h=h/10;
		if(c!=d){
			p++;
		}
	}
	cout<<p;
}
freopen("string.out","w",stdout);
    return 0;
}
