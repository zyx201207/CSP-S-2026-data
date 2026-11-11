#include<bits/stdc++.h>
using namespace std;
int n,l,r,ans;
long long m,a[500010];
int f(int k){
	long long sum=0;
	int cnt=0;
	for(int i=k;i>=1;i--){
		sum+=a[k]-a[i];
		if(sum>m)break;
		cnt++;
	}
	ans=max(ans,cnt);
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2; 
		if(f(mid))l++;
		else r--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
