#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main () {
	
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	string s="";
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		while(a--){
			s+=c;
		} 
	}
	string t=s;
	reverse(t.begin(),t.end());
	if(s.size()==2&&s!=t){
		cout<<"1";
		return 0;
	}
	if(s==t||s.size()==1){
		cout<<"0";
		return 0;
	}
	
	
	
	
	return 0;
} 
