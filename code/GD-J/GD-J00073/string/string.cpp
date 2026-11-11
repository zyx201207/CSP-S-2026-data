#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long b;
		char c;
		cin>>b>>c;
		for(int j=1;j<=b;j++){
			s+=c;
		}
	}
	long long b=s.size();
	for(int i=0;i<b/2;i++){
		if(s[i]!=s[b-i-1])
			ans++;
	}
	cout<<ans;
	return 0;
} 
