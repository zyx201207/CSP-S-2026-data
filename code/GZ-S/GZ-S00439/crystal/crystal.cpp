//GZ-S00439 黔南布依族苗族自治州都匀第一中学 胡昌志远 
#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],ans[500005]={1},maxn=0;
long long b[1000000];
long long c[1000000];
long long m;
void fin(int p){
	c[p]=0;
	b[p]=0;
	for(int i=p+1;i<=n;i++){
		b[i]=b[i-1]+c[i]*(i-p);
		if(b[i]>m){
			ans[p]+=i-p;
			return ;
		}
		if(i==n){
			ans[p]=n-p+1;
			return ;
		}
	}
	ans[p]=1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	a[0]=a[1];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		c[i]=a[i]-a[i-1];
//		cout<<c[i]<<" ";
	} 
//	cout<<endl;
	bool ss=1; 
	for(int i=2;i<n;++i){
		if(c[i]!=c[i+1]){
			ss=0;
			break;
		}
	}
	if(ss){
		fin(1);
		cout<<ans[1];
		return 0;
	}
	for(int i=1;i<=n;++i){
		fin(i);
		maxn=max(maxn,ans[i]);
	}
	cout<<maxn;
	return 0;
}
