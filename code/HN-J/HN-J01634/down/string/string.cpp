#include <bits/stdc++.h>
using namespace std;
long long n,m,sum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) {
		long long x;
		string y;
		cin>>x>>y;
		m+=x;
		while(x--) s+=y;
	}
	for(long long i=0;i*2<m;i++) {
		if(s[i]!=s[m-1-i]) sum++;
	}
	cout<<sum;
	return 0;
} 
