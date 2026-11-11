#include<iostream>
#include<string>
#define int long long
using namespace std;
int n;
int x;
char c;
string s;
int cnt;
bool hui(string l){
	for(int i=0;i<l.size();i++){
		if(l[i]!=l[l.size()-i-1]) return false;
//		cout<<l[i]<<" "<<l[l.size()-i-1]<<'\n';
	}
	return true;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){//构造字符串 
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s=s+c;
		}
	}
	int len=s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[len-i-1]) cnt++;
//		cout<<s[i]<<" "<<s[len-i-1]<<'\n';
	}
	cout<<cnt/2;
//	if(hui(s)){
//		cout<<0;
//		return;
//	}
//	//取前半或后半
//	//前半作为回文
//	string b;
//	for(int i=0;i<(len+1)/2;i++){
//		b=b+s[i];
//	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}
