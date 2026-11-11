#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
long long n=0,ab=0,bc=0;
cin>>n;
string a,b,c;
for(int i=0;i<n;i++){
	int x;
	string y;
	cin>>x>>y;
	ab+=x;
	for(int i=0;i<x;i++) a+=y;
}
int m=(ab+1)/2;
for(int i=0;i<m;i++) c+=a[i];
for(int i=ab-1;i>=m-1;i--) b+=a[i];

if(c==b){
cout<<0;
return 0;
}
for(int i=0;i<ab;i++){
	cout<<c[i]<<b[i]<<endl;
	if(c[i]!=b[i]) bc+=1;
}
cout<<bc;
	return 0;
}

