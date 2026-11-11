#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum[500005];
int maxn;
int l,r;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	l=r=1;
	while(l<=n and r<=n){
		if(sum[r]-sum[l-1]>m){
			while(sum[r]-sum[l-1]>m){
				l++;
			}
		}
		else{
			r++;
			while(sum[r]-sum[l-1]>m){
				l++;
			}
		}
		maxn=max(maxn,r-l+1);
	}
	cout<<maxn;
	return 0;
}
