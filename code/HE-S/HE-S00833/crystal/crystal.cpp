#include <bits/stdc++.h>
using namespace std;
long long a[500000+10];
long long m,ans=0;//m'检测 
bool c(long long x){
	long long sum=0;
	for(long long u=1;u<=x;u++){
		sum+=abs(x-a[u]);
		if(sum>m){
		
	     	sum=0;
			return 0;
		}
		}
			return 1;
	}

int main(){
	int n;
	cin >>n>>m;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin >>a[i];
	//	a[i]+=100000000005;
//	b[i]=abs(a[i]-a[i-1]);
		ans+=a[i];
	}
	sort(a+1,a+n+1);
	
	long long l=0,r=ans;
	while(l<=r){
		int mid=(l+r)/2;
//	cout << mid<<" ";
		if(c(mid)) {//如果说小了 
			l=mid+1;
		}
		else r=mid-1;
	
	}
//	l-=100000000005;
	//已经求出L为最优值 
	//cout <<endl<<l<<endl;
	ans=0;
	int df=0;
	for(int i=1;i<=n;i++){
	if(ans+abs(l-a[i])<=m) ++df;
	ans+=abs(l-a[i]);
	}
	cout << df; 
	return 0;
}
