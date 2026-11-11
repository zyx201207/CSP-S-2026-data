#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],s[N];
int n;
long long m;
bool cmp(long long x,long long y){
	return x>y;
}
bool check(int l,int x){
	int sum=a[l]*(x-l+1)-(s[x]-s[l-1]);
	if(sum<=m){
		return 1;
	}
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		int k=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(i,mid)){
				k=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,k-i+1);
	}
	cout<<ans;
	return 0;
}