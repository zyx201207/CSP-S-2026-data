#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,ans=0;
	string a;
	long long shu;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>shu>>a;
		while(shu>0){
			s+=a;
			shu--;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
