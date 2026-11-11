#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005]={},ans=0,x=0,leiji=0,flag1=1,flag2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag1=0;//特判性质A; 
		if((a[i]-a[i-1])!=(a[i-1]-a[i-2])&&i>=3) flag2=0;//特判性质B; 
	}
	sort(a+1,a+n+1);
	if(flag1){//特判性质A; 
		for(int i=1;i<=n;i++){
			if((a[i]*i-(1+i)*i/2)<=m) ans=i;
			else break;
		}
		cout<<ans;
		return 0;
	}
	if(flag2){//特判性质B; 
		for(int i=1;i<=n;i++){
			if((a[i]*i-(a[1]+a[i])*i/2)<=m) ans=i;
			else break;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		x=m;
		leiji=0;
		for(int j=i;j>=1;j--){
			if(a[j]==a[i]){
				leiji++;
				continue;
			}
			if(a[j]>a[i]) continue;
			if(x==0||(a[i]-a[j])>x) break;
			x-=a[i]-a[j];
			leiji++;
		}
		ans=max(ans,leiji);
	}
	cout<<ans;
	return 0;
}
