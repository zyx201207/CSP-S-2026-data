//贵阳市第一中 王怀威 GZ-S00249
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a[500005],n,m,ans1=1,ans2=0,s[500005],s2[500005]={0};
	cin>>n>>m>>a[1];
	for(int i=2;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) s[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++) {
		s2[i]=s2[i-1]+(i-1)*s[i];
	}
	int a1=2,b1=3;
	while(b1<=n&&a1<b1){
		if(s2[b1]-s2[a1]<=m){
			ans1++;
			b1++;
		}
		else {
			ans2=max(ans2,ans1);
			ans1--;
			a1++;
		}
	}
	ans2=max(ans2,ans1);
	cout<<ans2+1;
	return 0;
}