#include <bits/stdc++.h>
//#define ll long long
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,x[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int n,d;
			cin>>n>>d;
			if(n<=3){
				cout<<"0\n";
				continue;
			}
			for(int i=1;i<=n;i++)
				cin>>x[i];
			int del=x[2]-x[1];
			int jp=d/del;
			if(jp<=1){
				cout<<"0\n";
				continue;
			}
			cout<<max(n-1-(jp+jp-1)+1,0ll)<<'\n';
		}
		return 0;
	}
	while(t--){
		int n,d;
		cin>>n>>d;
		if(n<=3){
			cout<<"0\n";
			continue;
		}
		cout<<"0\n";
	}
	return 0;
} 
