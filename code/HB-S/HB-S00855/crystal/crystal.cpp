#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum[500005]={},mid=0,minn=INT_MAX;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (a[j]<=a[i]){
				sum[i]+=a[i]-a[j];
			}
		}
		minn=min(minn,abs(5-sum[i]));
	}
	mid=minn;
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		if (a[i]>mid) break;
		else if(a[i]==mid) ans++;
		else {
			if (mid-a[i]<=m){
				m-=mid-a[i];
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
