#include<bits/stdc++.h>
using namespace std;

int c,t;
long long v[2000010];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(v,0,sizeof v);
		long long n,k,ans=0;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x]++;
			v[y]++;
			ans=max(ans,v[x]);
			ans=max(ans,v[y]);
		}
		if(n/k*k!=n) n=n/k+1;
		else n=n/k;
		cout<<n/ans<<'\n';
	}
	return 0;
}
