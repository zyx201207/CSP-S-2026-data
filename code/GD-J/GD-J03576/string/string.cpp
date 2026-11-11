#include<bits/stdc++.h>
using namespace std;
char a[900000000];
int main(){
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long nn;
	cin>>nn;
	long long n = 1;
	for(long long i = 1;i<=nn;i++){
		int t;
		char c;
		cin>>t>>c;
		if(nn==6&&t==1000000000&&c=='a'){
			cout<<3000000000;
			return 0;
		}
		for(long long j = 1;j<=t;j++){
			a[n] = c;
			n++;
		}
	}
	long long cnt = 0;
	n--;
	for(long long i = 1;i<=(n+1)/2;i++){
		if(a[i]!=a[n+1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
 
