#include <bits/stdc++.h>
using namespace std;
int n,s[105],b[1000005],ans;
bool o,p;
char a[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		cin>>a[i];
		s[a[i]-96]+=a[i];
		if (i!=1) if (a[i]!=a[i-1]) o=1;
	}
	for(int i=1;i<=n/2;i++){
		if (b[i]!=b[n-i+1] || a[i]!=a[n-i+1]) p=1;
	}
	for(int i=1;i<=26;i++){
		if (s[i]==0) continue;
		if (s[i]%2==0) ans+=s[i]/2;
	}
	if (o==1 && p==1) cout<<ans;
	else cout<<"0";
	return 0;
}
