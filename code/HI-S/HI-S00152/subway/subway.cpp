#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=-1;
	sort(a+1,a+1+n);
	int cnt=0;
	for(int i=1;i<=n-m+1;i++){
		cnt=a[i]&a[i+1];
		for(int j=i+2;j<=m;j++){
			cnt&=a[j];
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 

