#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt[500010],a[500010],b[500010],pref[500010],maxn,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int p=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		ans+=(a[n]-a[i]);
	}
	if(ans<=m){
		cout << n;
		return 0;
	}
	ans=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if((a[i]-a[i-1])!=ans) p=0;
	}
	if(p){
		m/=ans;
		int w=1;
		for(int i=1;i<=n;i++){
			if(m>=i){
				m-=i;
				w++;
			}
			else break;
		}
		cout << w;
		return 0;
	}
	for(int i=n;i>=1;i--){
		int k=m,l=i-1;
		cnt[i]=1;
		while(l>0){
			if(k>=(a[i]-a[l])){
				k-=(a[i]-a[l]);
				l--;cnt[i]++;
			}
			else break;
		}
	}
	maxn=cnt[1];
	for(int i=2;i<=n;i++){
		maxn=max(maxn,cnt[i]);
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
