#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	for(int i=1;i<=n;i++){
		int cnt;
		char a;
		cin>>cnt>>a;
		string a1(a,cnt);
		s+=a1;
	}
	long long ans=0;
	for(int i=0;i<=s.size()/2-1;i++){
		if(s[i]!=s[n-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
