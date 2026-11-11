#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,mans=-1,now,now2;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<long long>());
	now=a[1];now2=1;long long m1=m;long long i=now2+1;
	while(now2<=n){
		if(mans>ans+n-i+1){
			m1=m;
			ans=1;
			if(now==a[now2+1]){
				while(now==a[now2+1]&&now2<=n){
					now2++;
				}
			}
			else now2++;
			now=a[now2];
			i=now2+1;
			continue;
		}
		long long yzx=now-a[i];
		if(m1>=yzx){
			m1-=yzx;
			ans++;
		}
		if(i>=n||m1<yzx){
			if(ans>mans)mans=ans;
			m1=m;
			ans=1;
			if(now==a[now2+1]){
				while(now==a[now2+1]&&now2<=n){
					now2++;
				}
			}
			else now2++;
			now=a[now2];
			i=now2;
		}
		i++;
	} 
	cout<<mans;
}
