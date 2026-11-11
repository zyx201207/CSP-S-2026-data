#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long f[200005];
int n;
long long m;
int tofind(int i){
	int l=1,r=i;
	int mid;
	while (l<=r){
		 mid=(l+r)/2;
		if (f[i]-f[mid]<=m){
			r=mid-1;
		}else {
			l=mid+1;
		}
	}
	return i-mid;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	int maxn=0;
	for (int i=n;i>=1;i--){
		maxn=max(maxn,tofind(i)+1);
	} 
	cout <<maxn;
	return 0;
} 
