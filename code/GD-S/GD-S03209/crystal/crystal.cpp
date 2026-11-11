#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500050];
long long pre[500050];//前缀和 
bool check(long long x){//如果m>=范围内所需能量则代表可行 
	for(int i=x;i<=n;i++){
		if(m>=(long long)(a[i]*x)-(long long)(pre[i]-pre[i-x])){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	long long l=0,r=n;
	while(l<r){
		long long mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;//二分答案 复杂度nlogn 

	return 0;
}
