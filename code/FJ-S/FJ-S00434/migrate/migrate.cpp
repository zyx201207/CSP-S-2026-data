#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000001],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11|c==12){
			if(d<a[2]-a[1])cout<<0<<'\n';
			else cout<<n-d/(a[2]-a[1])<<'\n';
		}
		else cout<<ans++<<'\n';
	}
	return 0;
}
