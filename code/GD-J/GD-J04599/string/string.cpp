#include<bits/stdc++.h>
using namespace std;
long long n,a,len,ans,l=0,r=1e9+1;
char ch;
string s;
bool hw(string str){
	bool flag=true;
	for(long long i=0;i<=(long long)(str.size())/2;i++){
		if(str[i] != str[str.size()-i-1]) flag=false;
	}
	return flag;
}
bool check(long long k,string str){
	if(hw(str)) return true;
	for(long long i= (long long)(str.size())/2;i<=str.size();i++){
		if(k<=0) break;
		if(str[i] != str[str.size()-i-1]){
			str[i] = str[str.size()-i-1];
			k--;
		}
	}
	if(hw(str)) return true;
	else return false;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>ch;
		while(a--){
			s = s+ch;
		}
	}
	while(l+1!=r){
		long long mid=(l+r+1)/2;
		if(check(mid,s)) r=mid;
		else l=mid;
	}
	cout<<r<<'\n';
	return 0;
}

