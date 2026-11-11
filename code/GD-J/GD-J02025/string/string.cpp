#include<bits/stdc++.h> 
using namespace std;

int n;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		char a;
		long long k;
		cin>>k>>a;
		for(long long j=1;j<=k;j++){
			s+=a;
		}
	}
	long long cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1]) ++cnt;
	}
	cout<<cnt;
	return 0;
} 
