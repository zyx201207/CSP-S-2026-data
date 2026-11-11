#include <bits/stdc++.h>
using namespace std;
long long n;
string s1;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=0;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j=1;j<=a;j++) s1+=c;
		l+=a;
	}
	if(l%2==0){
		for(long long i=0;i<l/2;i++){
			if(s1[i]!=s1[l-i-1]) ans++;
		}
	}
	else{
		for(long long i=0;i<=l/2-1;i++){
			if(s1[i]!=s1[l-i-1]) ans++;
		}
	}
	cout<<ans;
	return 0;
}
