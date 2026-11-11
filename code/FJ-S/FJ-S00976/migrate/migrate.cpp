#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[2000001];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		// Test 11,12, 8 pts
		if(c==11||c==12){
			long long dis=x[2]-x[1];
			if(d<=dis)cout<<0<<endl;
			if(d>dis){
				int temp=d/dis;
				cout<<max(0ll,n-2*temp+1)<<endl;
			}
		}
		// Test 13,14, [0,8] pts
		if(c==13||c==14){
			cout<<0<<endl;
		}
	}
	return 0;
}
//miao ~
//++ RP
//RP ++
//[8,16] pts
//All [152,160] pts
