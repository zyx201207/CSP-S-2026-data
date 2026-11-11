#include <bits/stdc++.h>
using namespace std;
int n,s=0,e=0; 
string a;
int b[1000000005];
bool qw(int z){
	for(int i=z,j=1;i>=e;i--,j++){
		if(a[i]!=a[j]){
			return 0;	
		}
	}
	return 1;
}
void qe(int z){
	for(int i=z,j=1;i>=e;i--,j++){
		if(a[i]!=a[j]){
			a[i]=a[j];
			s+=b[j];	
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int z=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int q;
		char w;
		cin>>q>>w;
		a[i]=w;
		b[i]=q;
	}
	if(n%2!=0){
		int e=n/2+1;
	}else{
		int e=n/2;
	}
	if(qw(z-1)){
		cout<<s;
		return 0;
	}
	qe(z-1);
	cout<<s;
	return 0;
}
