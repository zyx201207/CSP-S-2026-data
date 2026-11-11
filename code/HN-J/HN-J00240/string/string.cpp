#include<bits/stdc++.h>
#define int long long
using namespace std;
const int kMaxN=2e5+5;
int n;
int a[kMaxN];
char c[kMaxN];
int ans;
int lsum[kMaxN];
int rsum[kMaxN];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)lsum[i]=lsum[i-1]+a[i];
	for(int i=n;i>=1;i--)rsum[i]=rsum[i+1]+a[i];
	int l=1,r=n;
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		if(lsum[l]>lsum[n]/2)x=lsum[n]/2;
		else x=lsum[l];
		cout<<x<<'\n';
		while(rsum[r]<x){
			if(c[l]!=c[r]){
				ans+=rsum[r]-y;
			}
			y=rsum[r];
			r--;
		}
		if(c[l]!=c[r]){
			ans+=x-y;
		}
		y=x;
		l++;
	}
	cout<<ans;
	return 0;
}
