#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;

int n,m,a[500005],ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	int j=1,chasum=0;
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		chasum+=(i-j)*(a[i]-a[i-1]);
		while(chasum>m){
			chasum-=(a[i]-a[j]);
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}












