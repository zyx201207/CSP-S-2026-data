#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=0;
	cin>>n;
	string s;
	for(long long i=1;i<=n;i++){
		long long a;
		cin>>a;
		char b[2];
		cin>>b[0];
		for(long long j=1;j<=a;j++){
			s[m]=b[0];
			m++;
		}
	}
	long long maxn=0;
	for(long long i=0;i<m;i++){
		if(s[i]!=s[m-1-i]){
			maxn++;
			s[i]=s[m-1-i];
		}
	}
	cout<<maxn;
	return 0;
}
