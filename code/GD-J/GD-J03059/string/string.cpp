#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		while(x--){
			s+=c;
		}
	}
	string x=s;
	reverse(x.begin(),x.end());
	if(x==s){
		cout<<0;
		return 0;
	} 
	long long l=s.size(),cnt=0;
	for(int i=0;i<(l+1)/2;i++){
		if(s[i]!=s[l-i-1])cnt++;
	} 
	cout<<cnt;
	return 0;
}
