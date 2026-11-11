#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,m=0,sum=0;
	char c;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		for(long long j=0;j<a;j++){
			s[m]=c;
			m++;
		}
	}
	for(long long i=0;i<m/2;i++){
		if(s[i]!=s[m-1-i])sum++;
	}
	cout<<sum;
	return 0;
}
