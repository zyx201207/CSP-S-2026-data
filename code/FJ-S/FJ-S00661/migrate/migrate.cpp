#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,d,a[2000005],o,minn=LLONG_MAX;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t; 
	while(t--){
		cin>>n>>d;
		o=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1)
			    minn=min(minn,a[i]-a[i-1]);
		} 
		if(d<=minn){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i+3<=n;i++){
			o+=(n-(i+2));
		}
		cout<<o/2+1<<"\n";
	}
	return 0;
} 
