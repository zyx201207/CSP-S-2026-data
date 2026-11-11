#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int ans;
long long sum,need;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=0;
	for(l=1;l<=n;l++){
		sum-=a[l-1];
		while(r<n){
			sum+=a[r+1];
			need=(r+1-l+1)*a[r+1]-sum;
			if(need<=m){
				r++;
			} 
			else{
				sum-=a[r+1];
				break;
			}
		}
		ans=max(ans,r-l+1);
	} 
	cout<<ans;
	return 0;
}
