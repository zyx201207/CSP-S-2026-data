#include<bits/stdc++.h>
using namespace std;
const int N=6e5+15;
int	q[N],a[N],n,m,sum=0,ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	int l,r;
	l=1,r=0;
	for(int i=1;i<=n;i++){
		if(i>1)
		sum+=(r-l+1)*(a[i]-a[i-1]);
		while(l<=r&&sum>m){
			sum-=(a[i]-a[q[l]]);
			l++;
			
		}
		r++;
		q[r]=i;
		//cout<<sum<<" ";
		ans=max(ans,r-l+1);
		
	}
	cout<<ans;
	return 0;
}
