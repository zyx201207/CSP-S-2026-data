#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
string a;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m>>b;
		for(long long j=1;j<=m;j++) a+=b;
	}
	for(long long k=0;k<=a.size()/2-1;k++) if(a[k]!=a[a.size()-k-1]) ans++;
	cout<<ans;
	return 0;
}
