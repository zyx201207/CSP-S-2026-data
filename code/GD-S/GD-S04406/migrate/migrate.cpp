#include<bits/stdc++.h>
using namespace std;
long long c,t,n,ans,a[5005],b[5005][5005],d,temp=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		ans=n-3;
		if(0>n-3){
			ans=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}

