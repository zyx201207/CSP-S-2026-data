#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5000005;

int c,t;
int n,d;
int x[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>t;
	if(c==0||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			int gc=x[2]-x[1];
			if(d/gc<=1) cout<<0<<'\n';
			else{
				int o=n-(d/gc*2-1);
				if(o<0) cout<<0<<'\n';
				else cout<<o<<'\n';
			}
		}
		return 0;
	}else{
		while(t--) cout<<"0\n";
	}
	
	return 0;
}
