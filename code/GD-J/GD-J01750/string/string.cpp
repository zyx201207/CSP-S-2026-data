#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans,a[215414];
char c[215144];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;){
		if(a[i]==a[j]) ans+=a[i]*(c[i]!=c[j]),i++,j--;
		else if(a[i]>a[j]) ans+=a[j]*(c[i]!=c[j]),a[i]-=a[j],j--;
		else ans+=a[i]*(c[i]!=c[j]),a[j]-=a[i],i++;
	}
	cout<<ans;
}
