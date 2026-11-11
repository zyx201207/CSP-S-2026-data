#include<bits/stdc++.h>
#define ll long long
//unsigned long long
//priority_queue<int,vector<int>,greater<int>>
using namespace std;
ll n,m,a[500005],ans=1;
void solve(int mid){
	ll sum=1,s=m;
	for(int i=mid+1;i<=n;i++){
		if(a[i]==a[mid])sum++;
		else break;	
	}
	for(int i=mid-1;i>0;i--){
		if(s-(a[mid]-a[i])>=0){
			s-=(a[mid]-a[i]);
			sum++;
		}
		else break;
	}
	ans=max(sum,ans);
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=n;i>0;i--){
		if(ans>=i)break;
		solve(i);
		while(a[i-1]==a[i])i--;
	}
	cout<<ans;
	return 0;
}

