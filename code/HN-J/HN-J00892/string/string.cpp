#include<bits/stdc++.h>
using namespace std;
int n,l,ans;
string s="0";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;char y;
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			s+=y;
		}
	}
	l=s.size()-2;
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l-i+1])ans++;
	}
	cout<<ans;
	return 0;
}

