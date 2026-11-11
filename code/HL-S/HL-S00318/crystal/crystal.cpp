#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,ans=INT_MIN;
long long a[N];
long long qzh[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	qzh[1]=a[1];
	for (int i=2;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
//	for (int i=1;i<=n;i++){
//		cout<<qzh[i]<<"\n";
//	}
	long long l=1,r=1;
	while (r<=n){
		long long now=qzh[r]-qzh[l]+a[l];
		if (a[r]*(r-l+1)-now<=m){
			ans=max(ans,r-l+1);
			r++;
		}
		else l++;
	}
	cout<<ans;
	return 0;
}
