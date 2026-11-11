#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	long long n;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++)
		s+=b;
	}
	long long cnt=0;
	if(s.size()%2==0)
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])
			cnt++;
	}
		if(s.size()%2==1)
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])
			cnt++;
	}
	cout<<cnt;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
