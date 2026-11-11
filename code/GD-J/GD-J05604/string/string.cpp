#include<bits/stdc++.h>
using namespace std;
long long f(string a){
	long long x=0,b=a.size();
	for(long long i=0,j=b-1;i<b/2;i++,j--){
		if(a[i]!=a[j])x++;
	}
	return x;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,b;
	cin>>n;
	string z="";
	char d;
	for(long long i=0;i<n;i++){
		cin>>b>>d;
		for(long long i=0;i<b;i++)z+=d;
	}
	cout<<f(z);
	return 0;
}
