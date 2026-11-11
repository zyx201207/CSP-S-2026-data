#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s1="";
	for(int i=1;i<=n;i++){
		long long x;
		char ch;
		cin>>x>>ch;
		for(int i=1;i<=x;i++){
			s1=s1+ch;
		}
	}
	string s2=s1;
	reverse(s2.begin(),s2.end());
	int ans=0;
	for(int i=0;i<s2.size()/2;i++){
		if(s1[i]!=s2[i])ans++;
	}
	cout<<ans;
}
