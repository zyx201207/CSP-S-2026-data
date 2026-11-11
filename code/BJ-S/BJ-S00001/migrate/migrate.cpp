#include<bits/stdc++.h>
using namespace std;
long long a[2000005],n,c,d,t,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long b,c;
		cin>>b>>c;
		for(int i=2;i<n;i++){
			cin>>a[i];
		}
		if(d<(c-b)*2)cout<<0;
		else cout<<max(0,n-(d/(c-b)*2-1));
		cout<<'\n';
	}
    return 0;
}