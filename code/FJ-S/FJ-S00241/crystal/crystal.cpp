#include <bits/stdc++.h>
using namespace std;
long long n,m,maxd=0,ans=1,cnt=0,mm=0;
long long a[1000005]={0};
int main() {
	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==0){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[i]==a[j]){
					cnt++;
				}
			}
			maxd=max(maxd,cnt);
			cnt=0;
		}
		cout << maxd;
		return 0;
	}else{
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			mm=m;ans=1;
			for(int j=i;j>=1;j--){
				if(mm-(a[i]-a[j])<0){
					maxd=max(maxd,ans);
					continue;
				}else{
					mm=mm-(a[i]-a[j]);
					ans++;
				}
				
			}
		}
	}
	cout << maxd++;
	return 0;
}
