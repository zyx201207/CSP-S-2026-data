#include<bits/stdc++.h>
using namespace std;
long long m,l,r,n,a[500010],ans,maxn,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	r=1;
	maxn=a[1];
	while(l<=r&&r<=n){
		while(sum>m&&l<r){
			sum-=maxn-a[l];
			l++;
		}
		if(sum<=m){
			ans=max(ans,r-l+1);
		}
		r++;
		sum+=(a[r]-maxn)*(r-l);
		maxn=a[r];
	}
	cout<<ans;
	return 0;
}
