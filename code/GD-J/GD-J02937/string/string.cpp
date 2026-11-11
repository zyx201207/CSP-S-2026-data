#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n,ans=0,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(int y=1;y<=a;y++){
			s+=b;
		}
	}
	int l=0,r=s.size()-1;
	while(true){
		if(l>=r)break;
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
} 
