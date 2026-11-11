#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
long long n,a[N],m,sum,ans=0,cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}

	
	//sort(a+1,a+n+1);
	long long l=1;
	long long r=n;
	//while(l<=r){
		//long long mid=(r+l)>>1;
	//	if(check(a[mid],mid)){
		//	l=mid+1;
	//	}else{
		//	r=mid-1;
	//	}
//	}
	
//	cout<<r;
for(int i=1;i<=n;i++){
	for(int j=i;j>=1;j--){
		if(m>=sum+a[i]-a[j]){
			sum+=a[i]-a[j];
			cnt++;
		}else{
			break;
		}
	}
	ans=max(ans,cnt);
			cnt=0;
			sum=0;
}
cout<<ans;
	return 0;
}

