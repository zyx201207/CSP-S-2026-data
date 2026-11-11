#include<bits/stdc++.h>
using namespace std;
long long t,n,k;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>k>>c;
		for(long long i=n;i<n+k;i++){
			s[i]=c;
		}
		n+=k;
	}
	long long ans=0;
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
