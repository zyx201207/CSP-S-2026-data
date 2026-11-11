#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,a[N],minn=1e18,maxn,ans,c[N],n,sum,cnt1;
map<long long,long long> mp;
long long check(long long x){
	memset(c,-1,sizeof(c));
	for(int i=1;i<=n;i++){
		if(a[i]-x>=0) cnt1+=(a[i]-x);
		c[i]=abs(a[i]-x);
	}
	sort(c+1,c+n+1);
	sum=0;
	for(int i=1;i<=n;i++){
		if(sum+c[i]>m&&c[i]!=-1){
			return (i-1);
		}
		if(c[i]!=-1) sum+=c[i];
	}
	//cout<<sum;
	return n;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
		ans=max(ans,mp[a[i]]);
		maxn=max(a[i],maxn);
		minn=min(a[i],minn);	
	}
	long long k=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=k) flag=0;
	}
	if(flag){
		long long aa=0;
		for(int i=1;i<=n;i++){
			long long z=i*k+k;
			if((z*i)>2*m) {
				aa=i;
				break;
			}
		}
		if(!aa) aa=n;
		cout<<aa;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=minn;j<=maxn;j++){
			ans=max(check(j),ans);
		}
	}
	cout<<ans;
	//5 5 1 2 4 8 9
	//5 8 -3 -1 2 2 7
	//5 6 1 2 3 4 5
	//3 1000000000 5 7 11
	//5 2 1 3 5 7 9
	return 0;
}
