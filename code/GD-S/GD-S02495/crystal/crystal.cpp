#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int a[500005],s[500005],n,m;
bool check(int mid,int r){
	int num=s[r]-s[mid-1];
	if(num+m>=a[r]*(r-mid+1)){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int rans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
		}
		if(i-ans+1>rans) rans=i-ans+1;
	}
	cout<<rans;
	return 0;
}
/*
10 5
1 2 3 4 5 6 7 8 9 10
*/
