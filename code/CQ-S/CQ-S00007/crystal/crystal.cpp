#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int n,m;
bool check(int l){
	int s=0,minn=1e18;
	int mid=l/2+1;
	for (int i=1;i<=l;i++){
		s+=a[i];
	}
	minn=min(minn,a[l]*l-s);
	for (int i=2;i<=n-l+1;i++){
		s+=a[l+i-1];
		s-=a[i-1];
		minn=min(minn,a[l+i-1]*l-s);
	}
	return minn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=0,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if (check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
}
/*
5 5
1 2 4 8 9

*/
