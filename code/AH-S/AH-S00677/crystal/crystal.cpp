#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n;
long long m;
long long a[N];
bool check(int ans){
	long long val=a[ans],tmp=m;
	for(int i=1;i<ans;i++){
		if(tmp<(val-a[i])){
			return false;
		}else if(val-a[i]==0) break;
		tmp-=(val-a[i]);
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n,mid=-1;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<l-1;
	return 0;
}
