#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,k,len,sum=0;
	string s;
	char c;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>k>>c;
		for(long long j=1;j<=k;j++) s+=c;
	}
	len=s.size();
	for(long long i=0;i<len/2;i++) if(s[i]!=s[len-1-i]) sum++;
	cout<<sum;
	return 0;
}

