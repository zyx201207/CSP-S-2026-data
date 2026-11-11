#include <bits/stdc++.h>
using namespace std;
string e[10000000];
long long a[10000000],n,b,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>e[i];
		b+=a[i];
	}
	string s[b];
	long long x=0,n=b-1;
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			s[x]=e[i];
			x++;
		}
	}
	for(long long i=0;i<floor(b/2);i++){
		if(s[i]!=s[n]){
			ans++;
		}
		n--;
	}
	cout<<ans;
	return 0;
}
