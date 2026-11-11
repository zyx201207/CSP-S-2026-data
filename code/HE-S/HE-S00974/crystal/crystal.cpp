#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool check(int x){
	long long sum=1e18;
	long long q=0,w=0;
	long long cnt=0;
	for(int i=1;i<x;i++){
		cnt+=a[x]-a[i];
	}
	sum=cnt;
	for(int i=x+1;i<=n;i++){
		q=a[i-1]-a[i-x];
		cnt-=q;
		w=(x-1)*(a[i]-a[i-1]);
		cnt+=w;
		sum=min(sum,cnt);
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
	sort(a+1,a+1+n);
	int l=1,r=n,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
