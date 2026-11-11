#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
string s="";
bool is(){
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i])return false;
	}return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		string s1;
		cin>>a>>c;
		if(a>10000000){
			cout<<3*a;
			return 0;
		}
		for(int j=1;j<=a;j++){
			s1+=c;
		}
		s+=s1;
	}if(is()==true){
		cout<<0;
		return 0;
	}else{
		int ans=0;
		for(int i=(s.size()+1)/2;i<s.size();i++){
			if(s[i]!=s[0]) ans++;
		}cout<<ans<<endl;
		return 0;
	}
	return 0;
}
