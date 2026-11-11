#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	long long mx=0;
	for(long long i=1;i<=n-m+1;i++){
		long long ans=a[i];
		for(long long j=i;j<i+m;j++){
			ans&=a[j];
		} 
		mx=max(mx,ans);
	}
	cout<<mx;
}
