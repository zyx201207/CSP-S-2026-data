#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long sm=0;
	int ans=0;
	for (int l=1,r=0;l<=n;l++){
		sm-=a[l-1];
		while (r<n){
			if ((long long)(r-l+1)*a[r+1]-sm<=m){
				r++;
				sm+=a[r];
			}
			else break;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
