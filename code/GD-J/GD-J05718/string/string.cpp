#include<bits/stdc++.h>
using namespace std;
int n;

//const int N=1e6+5;
//int a[N];
//long long len;
//char b[N];
string s;
int main(){
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		for(long long j=1;j<=x;j++){
			s+=y;
		}
	}
	long long t=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])t++;
	}
	cout<<t;
//	cin>>n;
//	len=0;
//	for(int i=1;i<=n;i++){
//		cin>>a[i]>>b[i];
//		len+=a[i];
//	}
	return 0;
}
