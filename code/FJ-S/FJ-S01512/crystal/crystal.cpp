#include<bits/stdc++.h>

using namespace std;
long long n;
long long ans=1,st=1,cnt=0;
long long m,a[500005],dis[500005];
int check(long long x,long long nnw){
	long long w=0; 
	for(long long u=st;u<=x-1;u++){
		w+=dis[nnw]-dis[u-1];	
	}
	if(cnt-w>m){
		return 1;
	}
	return 0;
}
long long find(long long nw){
	long long l=st+1,r=nw-1;
	while(l+1<r){
		long long mid=(l+r)/2;
		if(check(mid,nw)){
			r=mid;
		}
		else{
			l=mid;
		}
	} 
	return r+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		dis[i]=dis[i-1]+a[i]-a[i-1]; 
	}
	for(long long i=1;i<=n;i++){
		if(cnt<m){
			cnt=cnt+dis[i]-dis[st];
		}
		if(cnt>m){
			long long nst=find(i);
			for(long long j=st;j<=nst;j++){
				cnt-=dis[i]-dis[j-1];
			}
			st=nst;
		}
		ans=max(i+1-st,ans);
	}
	cout<<ans;
	return 0;
}

