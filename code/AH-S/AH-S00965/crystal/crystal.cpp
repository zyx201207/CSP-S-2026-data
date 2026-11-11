#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;

int n,ans,sum,m;

long long a[N],b[N];

int findans(int end){
	long long l=1,r=end;
	while(l<r){
		long long mid=(l+r)/2;
		long long k=end-mid+1;
		//cout<<l<<" "<<mid<<' '<<r<<" "<<k*b[end]-(a[end]-a[mid-1])<<endl;
		if(k*b[end]-(a[end]-a[mid-1])<=m)r=mid;
		else l=mid+1;
	}
	return end-l+1;
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		a[i]=b[i]+a[i-1];
		
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//		cout<<b[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//		cout<<a[i]<<" ";
//	cout<<endl<<endl;
		
	for(int i=1;i<=n;i++){
		ans=max(ans,findans(i));
	}
	cout<<ans<<endl;

	return 0;
}


