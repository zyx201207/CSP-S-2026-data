#include <bits/stdc++.h>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	long long a[n];
	char c[n];
	string s;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}

	for(long long i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
