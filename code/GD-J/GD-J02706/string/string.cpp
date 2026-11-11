#include <bits/stdc++.h>
using namespace std;
const int maxn=200014;
long long n,cnt=0;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x=0;
		char p='a';
		cin>>x>>p;
		string g(x,p);
		s+=g;
	}
	if(s.size()%2==0){
		long long p=s.size()/2;
		for(long long i=p;i<s.size();i++){
			if(s[p]!=s[s.size()-p-1]){
				cnt++;
			}
		}
	}
	else{
		long long p=s.size()/2;
		for(long long i=p+1;i<s.size();i++){
			if(s[p]!=s[s.size()-p-1]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
