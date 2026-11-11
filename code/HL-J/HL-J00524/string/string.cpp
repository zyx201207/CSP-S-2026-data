#include<bits/stdc++.h>
using namespace std;

int p[200005];
long long n,nam,ans;
string s,s1;
char c[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i]>>c[i];
		for(int j=0;j<p[i];j++){
			s+=c[i];
		}
		nam+=p[i];
	}
	for(int i=0;i<nam/2;i++){
		if(s[i]!=s[nam-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
