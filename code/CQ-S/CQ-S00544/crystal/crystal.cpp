#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,d;
ll a[2];
ll s,k=1;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	cin>>a[0];
	if(n>=2) cin>>a[1];
	if(n>=3){
		for(int i=2;i<n;i++){
			cin>>s;
		}
	}
	ll ans=0;
	d=a[1]>a[0]?a[1]-a[0]:a[0]-a[1];
	if(!d) m=0;
	while(1){
		if(m>=d*2*k){
			m-=d*2*k;
			ans+=2;
			k++;	
		}else{
			break;
		}
	}
	cout<<ans+1;
	return 0;
}
