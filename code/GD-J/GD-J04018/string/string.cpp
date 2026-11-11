#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,m=0;
	char b;
	string s="";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		m+=a;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	int ans=0;
	for(int i=0;i*2<m;i++){
		if(s[i]!=s[m-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
