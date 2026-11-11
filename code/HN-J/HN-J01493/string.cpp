#include <bits/stdc++.h>
using namespace std;
long long alllen=0,len;
int ans=0,n;
string words,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len>>words;
		alllen+=len;
		for(int j=1;j<=len;j++){
			s+=words;
		}
	}
	for(int i=0;i<alllen;i++){
		if(s[i]!=s[alllen-i]) ans++;
	}
	cout<<ans/2;
}
