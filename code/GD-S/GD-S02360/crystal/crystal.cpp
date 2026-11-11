#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[500005];
ll la[500005];
ll sla[500005];


int main() {
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	 
	ll m,n,ans=0;
	//scanf("%lld %lld", &n, &m);
	cin>>n>>m;
	
	
	for(ll i=0;i<n;i++) cin>>a[i];
	//scanf("%lld", &a[i]);
	
	sort(a, a+n);
	
	for(ll i=0;i<n-1;i++) la[i]=a[i+1]-a[i];

	sla[0]=0;
	
	for(ll i=1;i<n;i++) sla[i]=sla[i-1]+la[i-1];
	
	ll stai=1, cjian=sla[0];
	
	while(stai*sla[stai]-cjian<=m) {
		cjian+=sla[stai];
		stai++;
	}
	
	
	for(ll i=stai-1;i<n;i++) {
		ll de=m, j=i-1, cnt=1, dis;
		
		while(de>0&&j>=0) {
			dis=sla[i]-sla[j];
			de-=dis;
			if(de>=0) {
				cnt++;
				j--;
			}
			
		}
		
		
		ans = max(ans, cnt);
	}
		
		
	//printf("%lld", ans);
	
	cout<<ans; 
	return 0;
}
