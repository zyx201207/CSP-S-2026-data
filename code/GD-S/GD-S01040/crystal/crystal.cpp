#include<bits/stdc++.h>
using namespace std;
int n;
long long m,minn,maxn,ans;
long long a[500005];
bool check(int x){
	int sum=0;
	minn=1000000000005;
	maxn=-1000000000005;
	long long num=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x){
			break;
		}
		sum+=x-a[i];
		if(sum>m)break;
		num++;
	}
	ans=max(ans,num);
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	long long l=minn,r=maxn,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
