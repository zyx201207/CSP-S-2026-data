#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
int n;
ll m,A[N],sum[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>A[i];
	sort(A+1,A+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+A[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(A[i]*(i-mid)-(sum[i]-sum[mid])<=m)r=mid;
			else l=mid+1; 
		}
		ans=max(ans,i-l);
	}
	cout<<ans<<"\n";
	
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
