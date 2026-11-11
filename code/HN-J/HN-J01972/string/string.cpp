#include<bits/stdc++.h>
using namespace std;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,d=0,e=0;
	char c;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		for(long long i=0;i<a;i++){
			b[d]=c;
			d++;
		}
	}
	long long f=d+1;
	for(long long i=0;i<f/2;i++){
		if(b[i]!=b[d-1-i]){
			e++;
		}
	}
	cout<<e;
	return 0;
}
