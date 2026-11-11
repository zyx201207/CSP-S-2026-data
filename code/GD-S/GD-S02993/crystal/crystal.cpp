#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5+10;
ll m,n;
ll a[maxn];
ll zheng[110];
ll fu[110];
ll b[maxn];
struct node{
	ll x,y;			
};
bool cmp(node l,node r){
	return l.x<r.x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	ll job;
	bool flag = true;
	bool cha = true;
	for(ll i = 1;i<=n;i++){
		cin >> a[i];
		if(i>3){
		}
		if(a[i]>100){
			flag = false;
		}
		else{
			if(a[i]>0){
				zheng[a[i]]++;
			}
			else{
				fu[-a[i]]++;
			}
		}
	}
	sort(a+1,a+n+1);
	job = a[2]-a[1];
	for(ll i = 3;i<=n;i++){
		if(a[i]-a[i-1] != job){
			cha = false;break;
		}
	}
	if(n<=16&&m<=1000){
		ll ans = 1,sum = m;
		for(ll i = 1;i<=n;i++){
			ll cnt = 0;
			for(ll j = 1;j<=n;j++){
				b[j] = max(a[i]-a[j],a[j]-a[i]);
			}
			sort(b+1,b+n+1);
			for(ll j = 1;j<=n;j++){
				if(b[j]>sum){
					break;
				}
				else{
					cnt++;
					sum-=b[j];
				}
			}
			ans = max(ans,cnt);
			sum = m;
		}
		cout << ans;	
	}
	else if(cha == true){
		ll ans = 1;
		ll sum = 0;ll i = 1;
		while(sum<=m){
			sum = sum+job*i;
			if(sum<=m){
				sum = sum+job*i;
				if(sum<=m){
					ans+=2;
					i++;
				}
				else{
					ans+=1;
					break;
				} 
			}
		}
		cout << ans;
	}
	else if(flag == true){
		node d[220],e[220];
		ll j = 1;
		ll ans = 1;
		for(ll i = 0;i<=100;i++){
			if(zheng[i]>0){
				d[j].x = i;j++;
				d[j].y = zheng[i];
			}
			if(fu[i]>0){
				d[j].x = -i;j++;
				d[j].y = fu[i];
			}
		}
		for(ll i = 1;i<j;i++){
			ll cnt = 0,sum = m;
			for(ll k = 1;k<j;k++){
				e[k].x = max(d[i].x-d[k].x,d[k].x-d[i].x);	
				e[k].y = d[k].y;
			} 
			sort(e+1,e+j,cmp);
			for(ll k = 1;k<=n;k++){
				ll cat = sum%e[k].x;
				if(cat>=e[k].y){
					sum-=e[k].y*e[k].x;
					cnt+=e[k].y;
				}
				else{
					sum-=cat*e[k].x;
					cnt+=cat;
				}
			}
			ans = max(ans,cnt);
			sum = m;
		}
		cout << ans << endl;
	}
	
	return 0;
}
