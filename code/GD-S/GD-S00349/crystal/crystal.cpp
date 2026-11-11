#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[100005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int maxans=0;
	int l=1,r=1,sum=0;
	while(r<=n){
		cout<<l<<" "<<r<<" "<<sum<<endl;
		if(sum<=m){
			maxans=max(maxans,r-l+1);
			r++;
			sum+=(a[r]-a[r-1])*(r-l);
		}else{
			l++;
			sum-=a[r]-a[l-1];
		}
	}
	cout<<maxans;
	return 0;
}
