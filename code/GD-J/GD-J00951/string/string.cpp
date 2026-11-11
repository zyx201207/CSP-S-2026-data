#include<bits/stdc++.h>
using namespace std;
int len;
bool check(string s){
	string h="";
	for(int i=len-1;i>=0;i--){
		char t=s[i];
		h+=t;
	}
	return h==s;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int j=1;j<=n;j++){
		int p;
		char t;
		cin>>p>>t;
		len+=p;
		for(int i=1;i<=p;i++)s+=t;
	}
	int nl=len/2;
	if(check(s)){
		cout<<0;
		return 0;
	}
	int sum=0;
	for(int i=0;i<nl;i++){
		if(s[i]!=s[len-1-i])sum++;
	}
	cout<<sum;
	return 0;
} 
