#include <bits/stdc++.h>
using namespace std;
string s;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	long long b;
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>b;
		cin>>a;
		for(long long i=1;i<=b;i++){
			s+=a;
		}
	}

long long cnt=s.size();
	for(long long i=0;i<cnt/2;i++){
	
		
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	
	cout<<ans;
	return 0;
}

