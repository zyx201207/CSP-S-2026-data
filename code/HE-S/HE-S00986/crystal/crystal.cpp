#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
bool check(int x){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(x>a[i]){
			sum+=x-a[i];
		}
	}
	if(sum>m) return 0;
	return 1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int l=1e18;
	int r=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	int num=0;
	for(int i=1;i<=n;i++){
		if(l>=a[i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
