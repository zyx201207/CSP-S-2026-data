#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],b[N];
long long n,m;
bool check(int key){
	for(int i=1;i<=n-key;i++){
		long long sum=0;
		for(int j=1;j<=key;j++){
			sum+=(key-j)*a[i+j-1];
		}
		if(sum<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=0;
	
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	int l=0,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)==true){
			l=mid+1;
			ans=max(ans,mid);
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
