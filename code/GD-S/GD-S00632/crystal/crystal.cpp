#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],amin,xb,ans=1,cz,cnt,pd;
int yt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(long long i=1;i<=n;i++) cin >> a[i];
	for(long long i=1;i<=n-1;i++){
		xb = i;
		amin = a[i];
		for(long long j=i+1;j<=n;j++){
			if(amin > a[j]){
				amin = a[j];
				xb=j;
			}
		}
		a[xb]=a[i];
		a[i]=amin;
	}
	for(long long i=1;i<=n-1;i++){
		cz = a[i+1] - a[i];
		if(cz >= 0){
			yt=1;
			break;
		}
	}
	if(yt==1){
		for(long long i=2;i<=n;i++){
			for(long long j=1;j<i;j++){
				cnt=m;
				pd=0;
				for(long long z=j;z<i;z++){
					cz = a[i]-a[z];
					cnt-=cz;
					if(cnt < 0){
						pd = 1;
						break;
					}
				}
				if(pd==0){
					cz = i-j+1;
					ans = max(ans,cz);
				}
			}
		}
		cout << ans;
	}
	else cout << ans;
	return 0;
}
