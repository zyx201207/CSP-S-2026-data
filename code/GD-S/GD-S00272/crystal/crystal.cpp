#include<bits/stdc++.h>
using namespace std;
long long m;
int ans,n;
long long N[500005];
bool check(int k){
	long long m2=0;
	for(int i=1;i<=k;i++){
		m2+=N[k]-N[i];
	}	
	if(m2<=m) return 1;
	for(int j=k+1;j<=n;j++){
		m2-=N[j-1]-N[j-k];
		m2+=k*(N[j]-N[j-1]);
		if(m2<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>N[i];
	sort(N+1,N+n+1);
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
