#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005];
int n;
long long m;
bool check(int k){
	long long minn=m+1,sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(i>=k){
			minn=min(minn,k*a[i]-sum);
			sum-=a[i-k+1];
		}
	}
	return minn<=m;
}
int erfen(){
	int l=1,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	cout<<erfen();
	return 0;
} 
