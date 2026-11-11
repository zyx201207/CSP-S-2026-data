#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	while(n){
		n--;
		int a;
		char c;
		cin>>a>>c;
		while(a){
			a--;
			s+=c;
		}
	}	
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
