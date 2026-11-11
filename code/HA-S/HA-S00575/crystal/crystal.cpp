#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,f,ff,c;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) f=1;
		if(i==2) c=a[i]-a[i-1];
		if(i>2){
			if(a[i]-a[i-1]!=c) ff=1;
		}
	}
	if(!f){
		int cnt=0,k=m;
		c=0;
		for(int i=1;i<=n;i++){
			if(k-c<0) break;
			k-=c;
			c++;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	if(!ff){
		int cnt=0,k=m,sum=0;
		for(int i=1;i<=n;i++){
			if(k-sum<0) break;
			k-=sum;
			sum+=c;
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long cnt=1,k=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]>k) break;
			cnt++,k-=a[i]-a[j];
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
