#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,tot = 0,maxn = 1;
long long m,sum = 0;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	tot = n-1;
	for(int i = n;i>=1;i--){
		int ans = tot-1;
		while(ans>=1){
			if(sum+a[i]-a[ans]<=m){
				sum+=a[i]-a[ans];
				ans--;
			}
			else{
				break;
			}
		}
		tot = ans+1;
		if(tot==i){
			sum = 0;
		}
		else{
			sum-=(a[i]-a[i-1])*(i-tot);
		}
		maxn = max(maxn,i-tot+1);
	}
	cout<<maxn;
	return 0;
}
