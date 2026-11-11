#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,a;
	char b;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>b;
		for(long long j=1;j<=a;j++)
		s+=b;
	}
	long long k=0;
	for(long long i=0;i<s.size()/2;i++)
	if(s[i]!=s[s.size()-i-1]) k++;
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
