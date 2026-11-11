#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	long long n;
	cin>>n;
	string s="";
	
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		long long m;
		string t;
		cin>>m>>t;
		long long j=0;
		while(m--){
			s+=t;
		}
	}
	long long len = s.size();
	for(long long i=0;i<len;i++){
		if(s[i] != s[len-1-i]) cnt++;
	}
	
	cout<<cnt/2;
	return 0;
}