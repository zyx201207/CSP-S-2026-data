#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		while(x--){
			s+=c;
		}
	}
	string s2=s;
	reverse(s2.begin(),s2.end());
	if(s2==s){
		cout<<0;return 0;
	}
	long long i=0,j=s.size(),ans=0;
	while(i<j){
		if(s[i]!=s[j]){
			ans++;
			
		}j--;i++;
	}cout<<ans;
	return 0;
}

