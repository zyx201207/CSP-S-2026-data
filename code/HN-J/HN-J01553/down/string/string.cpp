#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	long long cnt=0;
	string s="";
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		long long x=a[i];
		while(x--){
			s=s+c[i];
		}
	}
	long long x=s.size();
	for(long long i=0;i<x/2;i++){
		if(s[i]!=s[x-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

