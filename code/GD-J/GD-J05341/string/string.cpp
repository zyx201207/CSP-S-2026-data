#include<bits/stdc++.h>
using namespace std;
int n,g;
char a;
string s="";
bool check(string s){
	string b=s;
	reverse(b.begin(),b.end());
	if(b==s){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>g>>a;
		for(int j=1;j<=g;++j){
			s+=a;
		}
	}
	if(check(s)){
		cout<<0;
		return 0;
	}
	int l=0,r=s.size()-1,ans=0;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
