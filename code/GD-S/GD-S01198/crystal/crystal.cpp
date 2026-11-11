#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
bool check(int st,int x){
	unsigned long long sum=0ll;
	for(int i=st;i<=x;i++){
		sum+=(a[x]-a[i]);
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long l=1,r=n,ans=0;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(1,mid)){
			l=mid+1;
			ans=max(ans,mid);
		}else{
			r=mid-1;
		}
	}
	int pos=0;
	int cnt=0;
	for(int i=n;i>ans;i--){
	//	bool f=0;
		while(i-ans>1&&check(i-ans,i)){
			//f=1;
		//	if(cnt==0)break;
			ans++; 
		}
	//	if(f)cnt++;
	}
	cout<<ans;
	return 0;
}
