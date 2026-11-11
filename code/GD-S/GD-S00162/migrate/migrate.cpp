#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,a[2000002],D,A,la[2000002],fi[2000002],ans,f;
queue<ll> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		D=0,A=0,ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;++i){
			cin>>a[i];
			if(i==2) D=a[2]-a[1];
			else if(i>2){
				if(D!=a[i]-a[i-1]){
					A=1;
				}
			}
		}
		if(!A){
			if(d<=D || d>=(n-1)*D){
				cout<<0<<"\n";
				continue;
			}
			ll l=2,r=n-2,mid;
			while(l<=r){
				mid=(l+r)>>1;
				if(mid*D>=d && (mid-1)*D<d){
					break;
				}
				if(mid*D<d){
					l=mid+1;
				}
				else if((mid-1)*D>=d){
					r=mid-1;
				}
			}
			cout<<max(1LL*0,n-2*mid+1)<<"\n";
			continue; 
		}
		
	}
	return 0;
} 
