#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cout<<i<<endl;
	}
	int r=1,ans=0;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		while(sum<=m&&r<n){
			sum+=(a[r]-a[r-1])*(r-i);
			r++;
		}
		ans=max(ans,r-i-1);
		sum-=a[r-1]-a[i];
	}
	cout<<ans;
    return 0;
}