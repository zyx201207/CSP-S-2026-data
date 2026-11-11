#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long m,a[N],s[N],s1[N];
bool check(int x){
	
	for(int i=x;i<n;i++){
		long long sum=0;
		for(int j=i-x+1;j<=i;j++){
			sum+=a[j];
		}
		if(sum<=m)return true; 
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
	for(int i=1;i<n;i++){
		s[i]=a[i+1]-a[i];
	}
	int l=0,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
