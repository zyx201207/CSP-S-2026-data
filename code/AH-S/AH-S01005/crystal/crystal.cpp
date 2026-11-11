#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long f[500010];
int l,r,ans,anss;
bool check(int mid,int k){
	long long num=f[k]-f[mid]-(mid-1)*(a[k]-a[mid]);
	if(num<=m)return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]>m){
			cnt++;
		}
	}
	if(cnt==n-1){
		cout<<0;
		return 0;
	}
	for(int i=2;i<=n;i++){
		f[i]=(i-1)*(a[i]-a[i-1])+f[i-1];
	}
	for(int i=1;i<=n;i++){
		int ans;
		l=1;r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)==1){
				r=mid-1;
				ans=i-mid+1;
			}
			else l=mid+1;
		}
		anss=max(ans,anss);
	}
	cout<<anss;
}
