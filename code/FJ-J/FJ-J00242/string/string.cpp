#include<bits/stdc++.h>
using namespace std;
int n,l,ans;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int g;
		char t;
		cin>>g>>t;
		l+=g;
		for(int j=1;j<=g;j++) a+=t;
	}
	for(int i=0;i<=l/2-1;i++) if(a[i]!=a[l-i-1]) ans++;
	cout<<ans;
}

