#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,ans=0;
	string s1,s2;
	
	cin>>n;
	
	long long a;
	char c;
	for(int i = 0;i < n;i++){
		cin>>a>>c;
		
		while(a--) s1 += c;
	}
	
	for(int i = s1.size()-1;i >= 0;i--){
		s2 += s1[i];
	}
	
	for(int i = 0;i < s1.size()/2;i++){
		if(s1[i] != s2[i]) ans++;
	}
	
	cout<<ans;
	
	return 0;
}
