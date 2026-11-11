#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=-1;
long long a[510005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long minn=INT_MAX-1000;
	long long maxn=-(INT_MAX-1000);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	long long l=minn;
	long long r=maxn;
	long long sum;
	long long c[510005];
	long long cnt=1;
	int flag=0;
	for(int i=l;i<=r;i++){
		sum=0;
		cnt=1;
		flag=0;
		for(int j=1;j<=n;j++){
			c[cnt++]=abs(i-a[j]);
		}
		sort(c+1,c+cnt);
		long long t=m;
		for(int k=1;k<=cnt-1;k++){
			if(flag==1){
				flag=0;
				break;
			}
			if(t>=c[k]){
				t-=c[k];
				sum++;
			}else{
				flag=1;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
