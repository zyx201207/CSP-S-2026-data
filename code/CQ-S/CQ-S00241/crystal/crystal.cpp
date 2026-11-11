#include<bits/stdc++.h>
using namespace std; 
const int N=5e5+5;
long long n,m,sum,l=1,r=1,a[N],ans=1,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	while(r<=n&&l<=r){
		if(r==n){
			while(l<n&&sum>m){
				k=a[n]-a[l];
				sum-=k;
				l++;
			}
			ans=max(ans,r-l+1); 
			break;
		}
		k=(a[r+1]-a[r])*(r-l+1);
		if(sum+k<=m){
			sum+=k;
			r++;
			ans=max(ans,r-l+1);
		}
		else sum-=a[r]-a[l++];
	}
	cout<<ans;
	return 0;
}
