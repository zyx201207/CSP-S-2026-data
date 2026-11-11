#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],l,r,ans=-2e18,d=0;
bool isA=true,isB=true;
bool check(long long x){
	long long sum=0,cnt=0;
	for(int i=x;i>=1;i--){
		if(sum-a[i]+a[x]<=m){
			sum+=a[x]-a[i];
			cnt++;
		}
	}
	if(cnt>ans){
		ans=cnt;
		return true;
	}else{
		return false;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	mt19937 RNG(time(0));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			isA=false;
		}
		if(i!=1){
			if(a[i]-a[i-1]!=d){
				isB=false;
			}
			d=a[i]-a[i-1];
		}
	}
	if(isA){
		long long num=sqrtl(2*m);
		for(int i=max(0ll,num-45000000);i<=num+45000000;i++){
			if((i+1)*i>2*m){
				//i-1
				cout<<min(i-1,n);
				return 0;
			}
		}
		return 0;
	}else if(isB){
		long long num=sqrtl(2*m);
		for(int i=max(0ll,num-45000000);i<=num+45000000;i++){
			if(2*i+i*i*d-i*d>2*m){
				//i-1
				cout<<min(i-1,n);
				return 0;
			}
		}
		return 0;
	}
	if(n<=10000){
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			long long sum=0,cnt=0;
			for(int j=i;j>=1;j--){
				if(sum-a[j]+a[i]<=m){
					sum+=a[i]-a[j];
					cnt++;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int _=1;_<=1000;_++){
		int i=RNG()%n+1;
		long long sum=0,cnt=0;
		for(int j=i;j>=1;j--){
			if(sum-a[j]+a[i]<=m){
				sum+=a[i]-a[j];
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
/*
只能增加，不能减少        
需要O(n log n)的时间复杂度
二分？ 
no 
*/
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
