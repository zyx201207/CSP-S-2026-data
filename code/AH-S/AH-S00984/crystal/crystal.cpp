#include<bits/stdc++.h>
using namespace std;
long long n,m,sum[500010],ans,t,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long x=1;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-x)-sum[i-1]+sum[x-1]>m){
			x++;
		}
		ans=max(ans,i-x+1);
	}
	cout<<ans<<endl;
	return 0;
}

