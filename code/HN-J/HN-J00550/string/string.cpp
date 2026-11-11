#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,ans,l;
string s1,s2,s3;
void check(string a,string b){
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) ans++;
	}
	return ;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;
		char b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			s3+=b;
		}
	}
	for(int i=0;i<s3.size()/2;i++){
		s1+=s3[i];
		s2+=s3[s3.size()-i-1];
	}
	l=s3.size()-1;
	if(s1==s2){
		cout<<0;
		return 0;
	}
	check(s1,s2);
	cout<<ans;
	return 0;
}

