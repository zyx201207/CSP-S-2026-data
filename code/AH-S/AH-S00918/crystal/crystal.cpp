#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long LL;
LL n,m;
LL a[N];
LL c[N];

bool check(int k){
	LL need=0;
	for(int i=k;i<=n;i++){
		need=0;
		for(int j=1;j<k;j++){
			need+=a[k]-a[i-j];
		}
		if(need>m) return 0;
	}
	return 1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		} else {
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

