#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+7;
ll m,n,a[N],b[N];
bool solve(int x){
	ll ans=1e17+7;
	if(x==2){
		for(int i=0;i<n-1;i++)ans=min(ans,a[i+1]-a[i]);
		//cout<<1;
		if(ans>m)return false;
		else return true;	
	}
	for(int i=x-1;i<n;i++){
	//	ll cnt=0;
	//	for(int j=i-x+1;j<i;j++){
	//		if(cnt>=ans)break;
	//		cnt+=abs(a[i]-a[j]);
	//	//	cout<<i<<" "<<cnt<<"!!!\n"; 
		//}
		ans=min(ans,b[i-x+1]-b[i]-(x-1)*(a[n-1]-a[i]));
	//	cout<<ans;
	}	
	if(ans>m)return false;
	else return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	b[n-1]=0;
	for(int i=n-2;i>=0;i--){
		b[i]=a[n-1]-a[i]+b[i+1];

	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2+1;
		//cout<<l<<" "<<r<<" "<<mid<<" \n";
		if(solve(mid)){
			l=mid;
		//	cout<<mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}

