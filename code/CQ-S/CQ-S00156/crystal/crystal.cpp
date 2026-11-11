#include<bits/stdc++.h>
using namespace std;
long long a[500005],g[500005],num[2000005],ans[2000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,minn=1000000000005;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
	}
	if(minn<0){
		for(long long i=1;i<=n;i++){
			a[i]-=minn;
		}
	}
	sort(1+a,1+a+n);
	long long ma=-1;
	for(long long i=n-1;i>=1;i--){
		ma=max(ma,a[i]);
	}
	for(long long i=1;i<n;i++){
		num[a[i]]++;
	}for(long long i=0;i<=ma;i++){
		ans[i]=num[a[i]];
	}
	for(long long i=2;i<n;i++){
		int x=m;
		for(long long j=a[i]-1;j>=0;j--){
			if(num[j]*(a[i]-j)<x){
				x-=num[j]*(a[i]-j);
				ans[i]+=num[j];
			}else{
				ans[i]+=(x/(a[i]-j));
				break;
			}
		}
	}
	long long maxx=-1;
	for(long long i=1;i<n;i++){
		maxx=max(ans[i],maxx);
	}
	cout<<maxx;
	return 0;
}

