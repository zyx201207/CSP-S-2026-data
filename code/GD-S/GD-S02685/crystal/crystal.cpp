#include <bits/stdc++.h>
using namespace std;
int n,p=1;
long long m,b,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
		if (i==1)continue;
		if (i==2)b=a[2]-a[1];
		else{
			if ((a[i]-a[i-1])!=b)p=0;
		}
	}
	sort(a+1,a+n+1);
	if (p==1){
		long long tot;
		long long t=m/b;
		for (int i=1;i<=n;i++){
			tot+=i;
			if (tot>t){
				cout << i;
				return 0;
			}
		}
	}
	int l=1;
	long long sum=0;
	ans=1;
	for (int r=2;r<=n;r++){
		sum+=(a[r]-a[r-1])*1ll*(r-l);
		while (sum > m&&l<=r){
			l++;
			sum+=(a[l-1]-a[r]);
		}
		if (l>r){
			continue;
		}
		ans=max(1ll*(r-l+1),ans);
	}
	cout << ans;
	return 0;
}
