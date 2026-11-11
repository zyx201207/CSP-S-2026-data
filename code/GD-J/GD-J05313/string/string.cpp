#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,a,k=0;
	string x="",b;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>b;
		for(long long i=0;i<a;i++){
			x+=b;
		}
	}
	long long l=x.length();
	for(long long i=0;i<n;i++){
		if(x[i]!=x[l-i+1]){
			x[l-i+1]=x[i];
			k++;
		}
		if(i==l-i+1||l-i-i+1==1)break;
	}
	cout<<k;
	return 0;
}
