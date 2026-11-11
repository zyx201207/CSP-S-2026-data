#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];

bool cmp(long long x,long long y){
	return x<y;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long nowstep,nowans,ans;
	ans=0,nowstep=0,nowans=0;
	long long j=n;
	for (long long i=n;i>=2;i--){
		//j: the first position waiting to check
		while (nowstep+a[i]-a[j]<=m&&j>=1){
			nowstep+=a[i]-a[j];
			nowans++;
			j--;
		}
		j++;
		//j:the last position that is ok
		ans=max(ans,nowans);
		if (j==i){
			j--;
			nowans=0;
			nowstep=0;
		}
		else{
			j--;
			nowstep-=(nowans-1)*(a[i]-a[i-1]);
			nowans-=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
