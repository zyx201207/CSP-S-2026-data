#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,cnt=0;
		cin>>n>>d;
		int a[n];
		for(int i=1;i<=n;i++){
			cin>>a[i];
			
		}
		for(int i=1;i<=n-3;i++){
			if((a[i+3]-a[i])%d){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}

	return 0;
}


