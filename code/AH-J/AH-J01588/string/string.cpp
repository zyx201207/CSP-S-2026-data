#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
long long a[N+5];
long long c[N+5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	long long n,f=1,h;
	cin>>n;
	char t;
	cin>>a[1]>>t;
	c[1]=t-'a';
	string s;
	h=a[1];
	for(long long j=1;j<=a[1];j++){
		s=s+(char)(c[1]+'0');
	}
	for(long long i=2;i<=n;i++){
		cin>>a[i]>>t;
		h+=a[i];
		c[i]=t-'a';
		for(long long j=1;j<=a[i];j++){
			s=s+(char)(c[i]+'0');
		}
		if(c[i]==c[1]){
			f++;
		}
	}
	if(f==n){
		cout<<"0";
		return 0;
	}
	int ans=0;
	for(long long i=0;i<h/2;i++){
		if(s[i]!=s[h+1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
