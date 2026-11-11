#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define MAXN 500005
ll n,m,pjs=-1e18-1,dow=1e18+1;
ll a[MAXN];

ll cha(ll a,ll b){
	if(a>b)return a-b;
	return b-a;
}


ll check(ll c){
	ll total=0;
	for(ll i = 1;i<=n;i++){
		ll pos = lower_bound(a+1,a+n+1,c)-a;
		ll lft = 1;
		ll rig = 1;
		total+=a[pos]-c;
		//cout << pos; 
		while(1){
			if((pos-lft<=0)||(pos+rig>n)){
				//cout << "len:" << rig+lft-2+1 << "total:" << total<<endl;
				return rig+lft-2+1;
			}
			if(total>=m){
				//cout << "len:" << rig+lft-2+1 << "total:" << total<<endl;
				return rig+lft-2+1;
			}
			if(cha(a[pos-lft],c)>cha(a[pos+rig],c)){
				total+=cha(a[pos+rig],c);
				rig++;
			}
			else
			{
				total+=cha(a[pos-lft],c);
				lft++;
			}//==?????????
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	bool sp_1=1,sp_2=1;

	for(int i=1;i<=n;i++){
		cin >> a[i];
		pjs = max(a[i],pjs);
		dow = min(a[i],dow);
		if(a[i]!=i)sp_1=0;
		if(i>=4&&a[i]-a[i-1]!=a[i-2]-a[i-3]){
			sp_2 = 0;
		}
	}
	sort(a+1,a+n+1);
	ll l =1,r=n,mid=(l+r)/2;
	ll ans = -1e18-1;
	if(n==1){
		cout << 1;
		return 0;
	}
	if(sp_1){
		ll nt = 1;
		while(1){
			if(nt>=n){
				cout << n;
				return 0;
			}
			if(m==nt*nt+nt){
				if(n%2==1)cout << nt*2+1;
				else cout << nt*2;
				return 0;
			}//is_bug??
			else if(m<nt*nt+nt){
				nt--;
				int kg = 0;
				if(m-(nt*nt+nt)>=nt)kg=1;
				if(n%2==1&&nt*2+1+kg<=n)cout << nt*2+1+kg;
				else if(nt*2+kg<=n) cout << nt*2+kg;
				else cout << n;
				return 0;
			}
			nt++;
		}		
	}
	else if(sp_2){
		ll ch = cha(a[1],a[2]);
		ll nt=1;
		while(1){
			if(m==(nt*(ch+nt*ch))){
				if(n%2==1)cout << nt*2+1;
				else cout << nt*2;
				return 0;
			}
			else if(m<=(nt*(ch+nt*ch))){
				int kg = 0;
				nt--;
				if((nt+1)*ch<=m-(nt*(ch+nt*ch))){
					kg=1;
				}
				if(n%2==1)cout << nt*2+1+kg;
				else cout << nt*2+kg;
				return 0;
			}
			nt++;
		}
		
	}
	if(pjs<=200005){
		for(int i = dow;i<=pjs;i++){
			ll t = check(i);
			if(t > ans){
				//cout << i << " ";
				ans = t;
			}
		}
	}// 1 2 3 4 5 6 7 8 9 qwqÉXÉm²»¶®°¡ 
	
	cout << ans;
	return 0;
}
