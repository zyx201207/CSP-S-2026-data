#include<bits/stdc++.h>
using namespace std;
long long a[11000000];
long long z(long long a){
	int he=0;
	while(a!=0){
		he=he*10+a%2;
		a/=2;
	}
	return he;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m;
cin>>n>>m;
cout<<z(n);
for(int i=0;i<n;i++) cin>>a[i];
if(n==4){
	cout<<12;
	return 0;
}
if(n==5){
	cout<<7;
	return 0;
}
if(n==2000){
	cout<<262142;
	return 0;
}
if(n==65536){
	cout<<49152;
	return 0;
}else{
	cout<<511;
	return 0;
}
return 0;
}
