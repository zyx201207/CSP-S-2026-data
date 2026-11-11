#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		long long c1;
		char c2;
		cin>>c1>>c2;
		for(long long j=0;j<c1;j++){
			s+=c2;
		}
	}
	long long a=s.size();
	for(long long i=0;i<a/2;i++){
		if(s[i]!=s[a-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
