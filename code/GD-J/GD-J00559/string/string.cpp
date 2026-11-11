#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	while(n--){
		int x;
		char c;
		cin>>x>>c;
		while(x--){
			s+=c;
		}
	}
	long long ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])	ans++;
	}
	cout<<ans;
	return 0;
}
