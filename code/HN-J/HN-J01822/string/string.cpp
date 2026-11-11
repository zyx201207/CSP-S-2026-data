#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s;
long long n,a[N],ans;
int r(string x){
	string t;
	for(int i=s.size()-1;i>=0;i--){
		t+=x[i];
	}
	if(x==t){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(r(s)==1){
			break;
		}
		if(s[s.size()-1-i]!=s[i]){
			s[s.size()-1-i]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

