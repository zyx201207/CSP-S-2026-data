#include <bits/stdc++.h>
using namespace std;

int a[500005],n,ans=0;
long long m;

bool check(int x){
	long long sum=0;
	for(int j=x-1;j>=1;j--){
		sum+=a[x]-a[j];
	}
	return sum<=m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);  
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
