#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	/*for(int i=0;i<s.size();i++){
		cout<<s[i]<<" ";
	}*/
	for(long long i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
			s[i]=s[s.size()-1-i];
			//cout<<i<<" ";
		}
	}
	cout<<ans;
	return 0;
}
