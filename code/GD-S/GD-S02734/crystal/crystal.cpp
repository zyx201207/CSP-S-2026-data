#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
ll m,k;
ll a[500005];
ll dif[500005];
ll pre[500005];
int maxn=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		k=a[i]-a[i-1];
		dif[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]+dif[i];
	}
	int l=2,r=2;
	ll tot=dif[2];
	while(r<=n){
		if(l>r&&r<n) r++;
		if(tot<=m){
			maxn=max(maxn,r-l+1);
			r++;
			tot+=dif[r]*(r-l+1);
		}
		else{
			l++;
			tot-=(pre[r]-pre[l-2]);
		}
	}
	cout << maxn+1;

	return 0;
}
