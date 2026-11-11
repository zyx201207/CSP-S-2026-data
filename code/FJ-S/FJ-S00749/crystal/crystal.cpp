#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m,ans=1;
	
	cin >> n >> m;
	vector<long long> a(n+1,0),d(n+1);
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	sort(a.begin()+1,a.end());
	
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	
	for(int i=2;i<=n;i++){
		int cnt=1,s=0;
		
		if(d[i]>m) break;
		
		if(i+ans>n) break;
		
		if(d[i+ans-1]*ans>m) break;
		
		while(i+cnt<n+2){
			s+=d[i+cnt-1]*cnt;
			if(s>m) break;
				
			cnt++;
		}
		
		ans=(ans>cnt?ans:cnt);
	}
	
	cout << ans;
	
	return 0;
}
