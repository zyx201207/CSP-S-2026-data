#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans,l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	l=n/2+1;
	for(long long i=1;i<=l;i++){
		if(b[i]==b[l]) continue;
		if(b[i]+m>=b[l]) m-=abs(b[l]-b[i]),b[i]=b[l];
	}
	for(long long i=1;i<=n;i++) if(b[i]==b[l]) ans++;
	cout<<ans;
	return 0;
}