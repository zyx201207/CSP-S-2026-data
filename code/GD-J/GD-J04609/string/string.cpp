#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;
	cin>>n;
	long long a;
	string c;
	string s;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	string s1;
	for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];		
	}
	if(s==s1)cout<<0;
	return 0;
}
