#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s="";
	for(long long i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	long long l=s.size();
	long long ans=0;
	long long i=0;
	while(i!=l-1-i){
		if(s[i]!=s[l-1-i]){
			ans++;
		}
		i++;
	}
	cout<<ans;
	return 0;
}
