#include<bits/stdc++.h>
using namespace std;
int s[200000000];
long long si,sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		int ch=c-'a'+1;
		for(int j=si+1;j<=a+si+1;j++){
			s[j]=ch;
		}
		si+=a;
	}
	for(int i=1;i<=si/2;i++){
		if(s[i]!=s[si-i+1]) ans++;
	}
	cout<<ans;
	return 0;
} 
