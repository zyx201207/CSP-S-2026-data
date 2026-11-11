#include<bits/stdc++.h>
using namespace std;
string s;
int main(){//66~78
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		long long q;char c;
		cin>>q>>c;
		for(int i=1;i<=q;i++){
			s=s+c;
		}
	}
	for(int i=0;i<=s.size()/2-1;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
