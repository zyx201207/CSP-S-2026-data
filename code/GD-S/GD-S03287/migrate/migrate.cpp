#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int> x(n+1);
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(ans==0)ans = x[i];
			ans=ans^x[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
