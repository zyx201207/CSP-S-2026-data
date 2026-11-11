#include<bits/stdc++.h>
using namespace std;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0;
	cin >> n;
	long long start=0;
	long long len=0;
	for(long long i=0;i<n;i++){
		long long m;
		char c;
		cin >> m >> c;
		len+=m;
		for(long long i=start;i<start+m;i++){
			s+=c;
		}
		start+=m;
	}
	int cnt=0;
	for(long long i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])cnt++;
	}
	cout << cnt;
	return 0;
}

