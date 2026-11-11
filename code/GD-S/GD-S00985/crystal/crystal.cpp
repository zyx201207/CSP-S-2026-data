#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[510000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,sum=0,ans=0;
	for(int r=1;r<=n;r++){
		int mid=(l+r+1)>>1;
		if(sum>m){
			while(sum>m){
				sum-=a[r]-a[l];
				l++;
			}
		}
		ans=max(ans,r-l+1);
		//cout<<sum<<" ";
		//cout<<mid<<"\n";
		sum+=(a[r+1]-a[r])*(r-l+1);
	}
	cout<<ans;
	return 0;
}/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
