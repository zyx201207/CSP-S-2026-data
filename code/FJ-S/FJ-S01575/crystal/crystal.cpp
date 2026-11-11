#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
long long m;
long long a[500010];
long long pre[500010];
int ans=0;
int check(int x,int fl){
	long long sum=pre[fl-1]-pre[x-1];
	long long cnt=fl-x;
	if(cnt*a[fl]-sum<=m){
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
