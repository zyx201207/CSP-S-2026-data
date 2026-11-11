#include<bits/stdc++.h>
#include<queue>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll lg[N];
ll ksm[30];
ll st[N][20];
ll n,m;
ll a[N];
ll sum[N];
ll ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	lg[1]=0;
	for(ll i=2;i<=N-9;i++){
		lg[i]=lg[i/2]+1;
	}
	ksm[1]=2;
	ksm[0]=1;
	for(ll i=2;i<=19;i++){
		ksm[i]=ksm[i-1]*2;
	}
	cin>>n>>m;
	bool fl=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]&&i!=1){
			fl=0;
			
		}
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(fl==0){
		//cout<<2;
		sort(a+1,a+1+n);
	}
	
	for(ll i=1;i<=n;i++){
		st[i][0]=a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(ll j=1;j<=19;j++){
		for(ll i=1;i<=n&&(n-(1<<(j-1)))>=i;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			
		}
	}
	ll l=1,r=1;
	/*for(ll i=1;i<=n;i++){
		ll oo=0;
		while(oo<i){
			oo+=(1<<lg[i-oo]);
		}
	}*/
	//return 0;
	for(r=1;r<=n;r++){
		while(1){
			ll ma=-1e15;
			ll l1=l;
			while(l1<=r){
				if(ma<st[l1][lg[r-l1]]){
					ma=st[l1][lg[r-l1]];
				}
				l1+=(1<<(lg[r-l1]));
			}
			ll cs=ma*(r-l+1)-(sum[r]-sum[l-1]);
			//cout<<l<<" "<<r<<" "<<cs<<" "<<ma<<"\n";
			if(cs>m){
				l++;
			}else{
				break;
			}
		}
		//cout<<l<<" "<<r<<"\n";
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
	
}

/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/

