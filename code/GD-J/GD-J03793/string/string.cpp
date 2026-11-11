#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	long long n,cnt=0;
	string s1,s2;
	cin>>n;
	for (long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for (long long j=1;j<=a;j++) s1+=c;
	}
	long long len=s1.size();
	for (long long i=len-1;i>=0;i--){
		s2+=s1[i];
	}
	for (long long i=0;i<len;i++){
		if (s1[i]!=s2[i]) cnt++;
	}
	cout<<cnt/2;
	return 0;
}
