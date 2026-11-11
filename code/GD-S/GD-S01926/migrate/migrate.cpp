#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long x[N];
void solve(){
	int n,d;cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	long long c=x[2]-x[1];
	bool f=true;
	for(int i=2;i<=n;i++)if(x[i]-x[i-1]!=d)f=false;
	long long cnt=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			bool f1=true;
			for(int i=l;i<=r;i++){
				if(x[i]+d>x[i+2]){
					f1=false;
					break;
				}
				if(x[i]+d<x[i+1]){
					f1=false;
					break;
				}
			}
			if(f1)cnt++;
		}
	}
	cout<<cnt<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
