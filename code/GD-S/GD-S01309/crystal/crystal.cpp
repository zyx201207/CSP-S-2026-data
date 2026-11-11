#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,m,a[500010];
bool check(int mid){
	for(int s=1;s<=n-mid+1;s++){
		int e=s+mid-1,cnt=0;
		int tar=a[e];
		for(int i=s;i<=e;i++){
			cnt+=abs(a[i]-tar);
		}
		if(cnt<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	int l=1,r=n,ans=0;
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1; 
		}
		else r=mid-1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
