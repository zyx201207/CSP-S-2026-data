#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005], ans=0;
int main(){
	freopen("crystal.in", "r", stdin);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(long long i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int i=2;
	while(m>0){
		long long tot=0;
		for(long long j=1; j<i; j++){
			tot += a[i]-a[j];
		}
	
		if(m<tot){
			break;
		}
		else if(m>=tot){ 
			for(long long j=1; j<i; j++) 	a[j] = a[i];
			ans = i;
			m = m-tot;
			i++;
		}
	}
	for(long long z=i; z<=n; z++){
		if(a[z] == a[i-1]) ans++;
	}
	cout << ans;
	freopen("crystal.out", "w", stdout);
	return 0;
} 
