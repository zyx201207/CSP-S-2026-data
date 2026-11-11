#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],d[500005],lwy=0,chy=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==a[i-1]) lwy++;
	}
	//Period A :)
	if(lwy==n-1){
		cout<<n;
		return 0;
	}

	sort(a+1,a+n+1);
	
	//Period B :|
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if(d[i]==d[i-1]) chy++;
	}
	if(chy==n-1){
		int bgg=d[n];
		if(m/bgg+1<=n) cout<<m/bgg+1;
		else cout<<n;
		return 0;
	}
	
	//Normal :( 
	int zans=0;
	for(int i=1;i<=n;i++){

		int use=m,now=i-1,ans=1;
		while(use>0&&now>0){
			if(a[i]-a[now]<=use) {
				ans++;
				use-=(a[i]-a[now]);
				now--;
			}
			else break;
		}
		zans=max(ans,zans);
	}
	cout<<zans;
	return 0;
}

