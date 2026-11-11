#include <bits/stdc++.h>
using namespace std;
string s="";
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	
	for(long long i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		
		for(long long i=1;i<=x;i++){
			s+=c;
			if(s.size()>=5e9){
				cout<<0;
				return 0;
			}
		}
	}
	
	for(__int128 i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
