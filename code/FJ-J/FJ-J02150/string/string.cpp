#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long cnt=0;
	string s="";
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		char c;
		cin>>c;
		while(a--){
			s+=c;
		}
	}
	int ans=0;
	for(int i=1;i<=s.size()/2;i++){
		if(s[i-1]!=s[s.size()-2-i]){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
