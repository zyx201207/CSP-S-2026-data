#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000005;
const long long hash=20100331;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d,c,T,m;cin>>c>>T;
	int k=0;
	ll dao[MAXN],copy[MAXN];
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>dao[i];
		if(d>=dao[n-1]-dao[n-2]||d<gongcha){
			cout<<0<<"\n";continue;
		}
	}
}


