#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,j=0,l=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		l+=a;
		for( ;j<l;j++){
			s[j]=c;
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]!=s[l-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
