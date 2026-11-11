#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=5e5+5;
int a[MAXN];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	
	sort(a+1,a+n+1);
	
	int p=1,q=0;
	int ans=0;
	while(p<=n){
		m-=(p-q)*(a[p+1]-a[p]);
		p++; 
		while(m<0){
			q++;
			m+=a[p]-a[q];
		}
		ans=max(ans,p-q); 
	}
	
	cout << ans;
	return 0;
} 
//FUCK CCF
