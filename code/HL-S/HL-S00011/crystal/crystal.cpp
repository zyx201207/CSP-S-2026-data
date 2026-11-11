#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l=0,r=0,q[1000005],sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(sum+(r-l)*(a[i]-q[r])<=m){
			sum+=(r-l)*(a[i]-q[r]);
			q[++r]=a[i];
		}
		else {
			while(sum+(r-l)*(a[i]-q[r])>m){
				sum=sum-q[r]+q[l];
				l++;
			}
			sum+=(r-l)*(a[i]-q[r]);
			q[++r]=a[i];
		}
		ans=max(r-l,ans);
	}
	cout<<ans;
	return 0;
}