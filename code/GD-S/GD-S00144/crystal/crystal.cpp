#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long f(long long x){
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x)break;
		ans+=x-a[i];
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	a[n+1]=0x3f3f3f3f3f3f3f3f;
	sort(a+1,a+n+2);
	int l=1,r=n+1;
	while(l<r){
		int mid=(l+r)/2;
		//cout<<mid<<" "<<f(a[mid])<<endl;
		if(m<f(a[mid])){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	cout<<l-1;
	
	return 0;
}
