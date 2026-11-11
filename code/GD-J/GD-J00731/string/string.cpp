#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		string tmp(a,c);
		s+=tmp;
	}
	if(s.size()%2==1){
		string lstr=s.substr(0,(s.size()-1)/2);
		string rstr=s.substr((s.size()-1)/2+1,(s.size()-1)/2);
		reverse(rstr.begin(),rstr.end());
		int ans=0;
		for(int i=0;i<(s.size()-1)/2;i++){
			if(lstr[i]!=rstr[i]){
				ans++;
			}
		}
		cout<<ans;
	}else{
		string lstr=s.substr(0,(s.size())/2);
		string rstr=s.substr((s.size())/2,(s.size())/2);
		reverse(rstr.begin(),rstr.end());
		int ans=0;
		for(int i=0;i<s.size()/2;i++){
			if(lstr[i]!=rstr[i]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
} 
