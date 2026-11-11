#include <bits/stdc++.h>
using namespace std;
long long n;
long long ans;
string s="",s1="";
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		while(a--){
			s=s+c;
			s1=c+s1;
		}
	}
	if(s==s1) cout<<0;
	else{
		for(int i=0;i<s.size();i++){
			int c=s[i]-s1[i];
			if(c!=0) ans++;
		}
		cout<<ans/2;
//		long long ans=0;
//		long long l=0,r=s.size()-1;
//		while(l<r){
//			if(s[l]!=s[r]){
//				ans++;
//			}
//			l++;
//			r--;
//		}
//		cout<<ans;
	}
	return 0;
}
