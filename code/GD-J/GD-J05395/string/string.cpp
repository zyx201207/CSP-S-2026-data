#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		string s1;
		cin>>s1;
		for(int j=1;j<=a;j++){
			s+=s1;
		}
	}
	
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
