#include<bits/stdc++.h>
using namespace std;
long long sum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n+1];
	char c[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) sum++;
	}
	cout<<sum;
} 

