#include<bits/stdc++.h>
using namespace std;
int n;
char s[100000005],w[100000005];
long long  ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long  b=1;
	cin>>n;
	if (n==1) cout<<0;
	for(int i=1;i<=n;i++){
		long long  a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s[b]=c;
			b++;
		}
	}
	b--;
	for(int i=1;i<=b;i++){
		w[i]=s[b-i+1];
	}
	long long d;
	if(b%2==0) d=b/2;
	else d=b/2+1;
	for(int i=1;i<=d;i++){
		if(s[i]==w[i]) continue;
		ans++;
	}
	cout<<ans;
	return 0;
}
