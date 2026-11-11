#include<bits/stdc++.h>
using namespace std;
struct F{
	long long a=0;string b;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,ans=0;
	cin>>n;
	vector<F> v(n);
	for(long long i=0;i<n;i++){
		cin>>v[i].a>>v[i].b;
	}
	string s="";
	for(long long i=0;i<n;i++){
		for(long long j=0;j<v[i].a;j++){
			s+=v[i].b;
		}
	}
	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}

