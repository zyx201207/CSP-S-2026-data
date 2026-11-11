#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2000006];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}unsigned long long nxt=a[2]-a[1];
		if(d<nxt){
			cout<<0<<endl;
			continue;
		}
		d=d/nxt*2;
		if(d<3){
			cout<<0<<endl;
			continue;
		} 
		if(n-d+1<0){
			cout<<0<<endl;
		}else cout<<n-d+1<<endl;
	}return 0;
}
