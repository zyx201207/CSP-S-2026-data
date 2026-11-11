#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1;
	long long sum=0;
	for(int r=2;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
