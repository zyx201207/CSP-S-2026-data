#include<bits/stdc++.h>
using namespace std;
int n;
long long m,sum,a[500005];
int ans=0;
int l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	ans=1;
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-l);
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
