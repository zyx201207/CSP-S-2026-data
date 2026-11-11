#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll a[N],n,m;
bool check(int x){
	ll cnt=0;
	for(int i=1;i<=n;i++){
		int tmp=i+x-1;
		if(i+x-1>n) break;
		for(int j=i,k=1;k<=x;j++,k++){
			cnt+=abs(a[tmp]-a[j]);
		}
		if(cnt<=m) return 1;
		cnt=0;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ll l=0,r=n,mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
