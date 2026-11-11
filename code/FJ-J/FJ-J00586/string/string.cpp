#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char b[200005];
string s="";
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[n-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}
