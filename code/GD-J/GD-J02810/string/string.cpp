#include <bits/stdc++.h>
using namespace std;
long long ans=0;
void huiwen(string s){
	for(long long i=0;i<s.size()/2;i++){
		if(s[s.size()-i-1] != s[i]){
			ans++;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin>>n;
	long long a;
	char ch;
	string s="";
	for(int i=0;i<n;i++){
		cin>>a>>ch;
		for(long long j=0;j<a;j++){
			s=s+ch;
		}
	}
	huiwen(s);
	cout<<ans;
	return 0;
} 
