#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,c=1e12;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long mm=m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long cnt=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])cnt++;
		if(a[i]-a[i-1]>0)c=min(c,a[i]-a[i-1]);
	}
	ans=cnt;
	while(m--){
		sort(a+1,a+1+n);
		a[1]++;
		cnt=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1])cnt++;
		}
		ans=max(ans,cnt);
	}
	if(c>=mm&&ans<2)cout<<2;
	else cout<<ans;
	return 0;
}
