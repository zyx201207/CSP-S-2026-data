#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N],sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=n,r=n;
	while(1<=l){
		sum+=a[r]-a[l];
		if(sum>m){
//			cout<<l<<" "<<r<<" "<<sum;
			ans=max(ans,r-l);
			sum-=(a[r]-a[r-1])*(r-l);
//			cout<<" "<<sum<<endl;
			r--;
		}
		l--;
	}
	cout<<max(r-l,ans);
	return 0;
}
