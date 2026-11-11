#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long n,zong=0,l=0;
	cin>>n;
	long nm[n];
	char m[n];
	string a;
	for(long i=0;i<n;i++){
		cin>>nm[i];
		cin>>m[i];
	}
	for(long i=0;i<n;i++){
		for(long j=0;j<nm[i];j++){
			a=a+m[i];
		}
	}
	for(long i=a.size()-1;i>=0;i--){
		if(a[i]!=a[l]){
			zong++;
		}
		l++;
	}
	cout<<zong/2;
	return 0;
}
