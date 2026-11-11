#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
0 1
6 2
-4 -3 -2 -1 3 6



*/
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n;
		ll d;
		cin>>n>>d;
		vector<int>ve;
		bool f=1;
		ll a[200005];
		for(int i=1;i<=n;i++){
			cin>>a[i];
			
			if(i>=3){
				if(a[i]-a[i-1]!=a[i-1]-a[i-2])f=0;
			}
		}
		if(f){
			ll gc=a[2]-a[1];
			if(d<=2*gc){
				cout<<0<<endl;
				continue;
			}
			ll k=d/gc;
			ll ans=n-2*k+1;
			if(ans<0)ans=0;
			cout<<ans<<endl;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int bs=1;
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d){
					bs++;
					//idx=j;
				}
				if(bs>1){
					//cout<<i<<" "<<j<<endl;
					int cnt=0;
					for(int l=i+1;l<j;l++){
						if(a[l]-a[i]*(bs-1)<=d&&a[j]-a[l]<=d){
							cnt++;
						}
					}
					if(cnt==2)ans++;
				}
//				idx++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
