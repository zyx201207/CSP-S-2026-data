#include<bits/stdc++.h>
using namespace std;
string s1="";
int n,ans=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a[n+5];
	char s[n+5];
	for(int i=0; i<n; i++) {
		cin>>a[i]>>s[i];
		for(int j=0; j<a[i]; j++) {
			s1=s1+s[i];
		}
	}
	int l=0,r=s1.size()-1;
	while(r>=0&&l<=s1.size()-1){
		if(s1[l]!=s1[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans/2;
	return 0;
}
