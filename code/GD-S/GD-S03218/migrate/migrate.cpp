#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2000005];
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(d<x[2]-x[1]){
			cout<<0<<endl;
			continue;
		}
		d=d/(x[2]-x[1])*(x[2]-x[1]);
		for(int i=0;i<n;i++){
			if(i+d*2-1<n)ans++;
		}
		cout<<ans<<endl;
	}
}
