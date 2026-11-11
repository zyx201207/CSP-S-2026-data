#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int cnt;
		string t;
		cin>>cnt;
		cin>>t;
		for(int j=1;j<=cnt;j++){
			s+=t;
		}
	}
	string s1=s;
	reverse(s1.begin(),s1.end());
	if(s==s1){
		cout<<0;
		return 0;
	}
	int len=s.size()-1,ans=0;
	if(len%2==1){
		for(int i=0;i<len/2;i++){
			if(s[i]!=s[len-i]) ans++;
		}
	}
	else{
		for(int i=0;i<=(len-1)/2;i++){
			if(s[i]!=s[len-i]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
