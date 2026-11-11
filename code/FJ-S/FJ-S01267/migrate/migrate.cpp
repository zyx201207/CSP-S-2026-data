#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n;
		long long d,a[2000006];
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(d<=a[2]-a[1]) cout<<0<<'\n';
		else if(a[n]-a[1]>=d*2-(a[2]-a[1])){
			cout<<n-((d*2-a[2]+a[1])/(a[2]-a[1]))<<'\n';
		} else cout<<0<<'\n';
	}
	return 0;
}
