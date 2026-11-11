#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s,r,l;
char c;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
	int t;
		cin>>t>>c;
		for(long long j=1;j<=t;j++){
			s=s+c;
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		l+=s[i];
	}
	for(long long i=s.size()/2+1;i<s.size();i++){
		r+=s[i];
	}
	for(long long i=0;i<l.size();i++){
		if(l[i]!=r[i]) ans++;
	}
	cout<<ans;
}
