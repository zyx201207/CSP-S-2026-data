#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,ans,minn=1e9,mi,mw,cc[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long c=0;
		for(int j=1;j<=n;j++){
			c+=abs(a[i]-a[j]);
		}
		if(c<minn) {
			mi=a[i];
			mw=i;
			minn=c  ;
		}
	}
	for(int i=0;i<n;i++){
		cc[i]=abs(mi-a[i]);
	}
	sort(cc,cc+n);
	for(int i=1;i<n;i++){
		if(m>=cc[i]){
			m-=cc[i];
			ans++;
		}
		else if(m<cc[i]){
			break;
		}
	}
	if(ans>0) cout<<ans+1;
	else cout<<0;
	return 0;
}
