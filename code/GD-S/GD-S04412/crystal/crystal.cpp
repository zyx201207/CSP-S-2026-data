#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
long long n,m,a[N],ans;
bool check(long long x){
	long long cnt=a[n],sum=0;
	for(long long i=n;i>0&&i>n-x;i--){
		sum+=cnt-a[i];
	}
	long long anss=sum;
	for(long long i=n-x;i>0;i--){
		cnt=a[i+x-1];
		sum=sum-(a[i+x]-a[i+x-1])*(x-1)+cnt-a[i];
		anss=min(anss,sum);
	}
	
	return anss<=m;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long cnt=a[n],sum=0;
	for(long long i=n;i>0;i--){
		sum+=cnt-a[i];
	}
	if(sum<=m){
		cout<<n<<endl;
		return 0;
	}
	long long l=0,r=N-50,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0; 
} 

