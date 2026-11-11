#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a[n+1];
	char b[n+1];
	long long l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		l+=a[i];
	}
	if(l>=1000005) return 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-1-i]){
		    ans++;
	    }
	}
	cout<<ans;
	return 0;
}
