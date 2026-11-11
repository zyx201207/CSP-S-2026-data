#include<bits/stdc++.h>
using namespace std;
const long long N=2*1e5+20;
long long n,sum,b[N];
string s;
bool hui(string s){
	if(s.size()==1){
		return true;
	}
	for(long long i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i]){
			return false;
		}else{
			continue;
		}
	}
	return true;
}
string fan(string s){
	string f;
	for(long long i=s.size()-1;i>=0;i--){
		f+=s[i];
	}
	return f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char x;
		cin>>a>>x;
		for(long long j=0;j<a;j++){
			s+=x;
		}
	}
	if(hui(s)){
		cout<<"0";
	}else{
		long long ans=0;
		string g;
		for(long long i=0;i<s.size()/2;i++){
			g+=s[i];
		}
		string f=fan(g);
		int j=0;
		for(long long i=s.size()/2+1;i<s.size();i++){
			if(f[j]!=s[i]){
				ans++;
			}
			j++;
		}
		cout<<ans;
	}
	return 0;
}
