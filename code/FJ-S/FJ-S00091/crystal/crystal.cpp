#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1e6,minn=1e6+6,a[500005],c[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1);
	long long gc=a[2]-a[1],flag=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=gc)flag=0;
	}
	if(flag){
		long long k=m,sum=0,cnt=0,t=a[(n+1)/2];
		for(int j=1;j<=n;j++){
			if(t>=a[j]){
				c[j]=t-a[j];
				cnt++;
			}else break;
		}
		for(int j=cnt;j>=1;j--){
			if(k-c[j]>=0){
				sum++;
				k-=c[j];
			}
		}
		if(sum==0)sum++;
		cout<<sum;
	}else{
		for(int i=minn;i<=maxn;i++){
			long long k=m,sum=0,cnt=0;
			for(int j=1;j<=n;j++){
				if(i>=a[j]){
					c[j]=i-a[j];
					cnt++;
				}else break;
			}
			for(int j=cnt;j>=1;j--){
				if(k-c[j]>=0){
					sum++;
					k-=c[j];
				}
			}
			if(sum==0)sum++;
			ans=max(sum,ans);
		}
		cout<<ans;
	}
	return 0;
}

