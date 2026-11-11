#include<bits/stdc++.h>
using namespace std;
long long n,p,ans;
long long a[277777];
char c[277777];
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		p+=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<p/2;i++){
		if(s[i]!=s[p-i-1]){
			ans++;
		}
	}
	
	cout<<ans;
	return 0;
}
