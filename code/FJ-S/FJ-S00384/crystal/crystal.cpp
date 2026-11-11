#include <bits/stdc++.h>
using namespace std;
int n,sum=0;
long long m,a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=(i-1)*(a[i]-a[i-1])+b[i-1];
	int l=1,r=1;
	while(r<=n){
		long long x=b[r]-(l-1)*(a[r]-a[l])-b[l];
		if(x<=m){
			sum=max(sum,r-l+1);
			r++;
		}
		else l++;
	}
	cout<<sum;
	return 0;
}
