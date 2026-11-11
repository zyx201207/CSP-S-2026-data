#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
long long d[500005],ans,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m>>a[1];
	bool f=1;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		d[i]=abs(a[i]-a[i-1]);
		if(i==2)continue;
		if(d[i]!=d[i-1])f=0;
	}
	if(f){
		if(a[2]==a[3])cout<<n;
		int lo=1;
		while(lo<=n && m>=lo*(lo+1)){
			lo++;
		}
		cout<<lo;
		return 0;
	}
	for(int i=2;i<=n;i++){
		int t=0,x=i;
		while(x<=n){
			t+=d[x];
			if(t>m)break;
			x++;
		}
		ans=max(ans,(long long)x-i+1);
	}
	cout<<ans;
}
