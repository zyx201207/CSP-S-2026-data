#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long sum=m,r=n,l=n-1,cnt;
	while(r>=1){
		while(l>=1){
			if(sum>=a[r]-a[l-1]&&l!=1){
				l--;
				sum-=a[r]-a[l];
			}
			else
				break;
		}
		ans=max(ans,r-l+1);
		sum+=(r-l)*(a[r]-a[r-1]);
		r--;
	}
	cout<<ans;
	return 0;
} 
