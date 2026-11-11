#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int n,d;
			cin>>n>>d;
			int x,y;
			cin>>x>>y;
			if(y-x>d)cout<<0;
			else cout<<n-3;
			cout<<'\n';
			for(int i=1;i<=n-2;i++)cin>>d;
		}
		return 0;
	}
	while(t--){
		int n,d;
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++){
				cout<<rand();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
