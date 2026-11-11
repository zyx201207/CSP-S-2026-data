#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m;
long long a[500010],c[500010],b[500010],ans,sum[500010];
bool ch(int mi){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[mi]>=a[i]){
			c[i]=a[mi]-a[i];
		}else{
			c[i]=9999999999;
		}
	}
	for(int i=1;i<=n;i++){
		if(m>=c[i]){
			m-=c[i];
			b[i]=a[mi];
			cnt++;
		}else{
			break;
		}
	}
	if(cnt>0){
		ans=max(ans,cnt);
		return 1;
	}else{
		return 0;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>=5000){
		sum[1]=0;
		for(int i=2;i<=n;i++){
			sum[i]=sum[i-1]+a[i-1];
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			if(m<sum[i]){
				cout<<i-1;
				break;
			}
		}
		return 0;
	}
	/*
	int o=1;
	for(int i=2;i<=n;i++){
		c[o++]=a[i]-a[i-1];
	}
	*/
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(ch(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
