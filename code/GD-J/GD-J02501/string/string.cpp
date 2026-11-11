#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin>>a;
	string s="";
	for(int i=0;i<a;i++){
		int k;char c;
		cin>>k>>c;
		for(int i=0;i<k;i++){
			s+=c;
		}
	} 
	int ans=0;
	for(int i=s.size()/2;i>=0;i--){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
