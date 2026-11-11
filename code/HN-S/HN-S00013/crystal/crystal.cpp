#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],c[N],dp[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1)
			c[i]=a[i]-a[i-1];
	}
	sum[2]=c[2];
	for(int i=3;i<=n;i++){
		sum[i]=c[i]*2;
	}
	ll l=2,r=2,mans=0,ans1=0;
	while(l<=r&&r<=n){
		t=0;
		if(ans1<m){
			ans1=ans1+sum[r];
			if(ans1<=m){
				while(a[r]==a[r+1]){
					r++;
				}
				mans=max(mans,r-l+1);
				ans1-=sum[l];
				l++;
				t=1;
			}
			r++;
		}
		else if(ans1>m){
			ans1=ans1-sum[l];
			if(ans1<=m){
				while(a[r]==a[r+1]){
					r++;
				}
				mans=max(mans,r-l+1);
				ans1-=sum[l];
				l++;
				t=1;
			}
			l++;
			r++;
		}
		if(ans1<=m){
			while(a[r]==a[r+1]){
				r++;
			}
			mans=max(mans,r-l+1);
			ans1-=sum[l];
			l++;
			r++;
			t=1;
		}
	}
	cout<<mans+2;
	return 0;
}
