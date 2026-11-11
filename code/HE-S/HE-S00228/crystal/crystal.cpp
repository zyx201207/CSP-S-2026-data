#include<bits/stdc++.h>
using namespace std;
long long n,m,cha;
int ans;
long long a[500010];
bool isB(){
	for(int i=2;i<n;i++){
		if((a[i]-a[i-1])!=(a[i+1]-a[i]))return false;
	}
	return true;
}
bool check(int x){
	long long mo=(x-1)*cha;
	return (mo+mo*mo)/2<=m;
}
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=5000){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int anss=0,k=0;
			for(int j=i;j>=1;j--){
				k+=a[i]-a[j];
				if(m-k>=0)anss++;
				else break;
			}
			ans=max(anss,ans);
		}
		cout<<ans;
	}else if(isB()){
		cha=a[2]-a[1];
		int l=0,r=n,mid; 
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid))l=mid+1,ans=mid;
			else r=mid-1;
		}
		cout<<ans;
	}
	return 0;
} 
