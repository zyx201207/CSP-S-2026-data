#include<bits/stdc++.h>
using namespace std;
long long n,ans,len;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		string t;
		cin>>m>>t; 
		for(int j=1;j<=m;j++){
			s+=t;
			len++;
		}
	}
	for(long long i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]) ans++;
	}
	cout<<ans;
}
