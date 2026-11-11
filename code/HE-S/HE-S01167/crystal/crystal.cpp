#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=-1;
bool check(vector<long long> &a,long long x){
	int l=0,r=x-1;
	long long cnt=0;
	for(int i=0;i<=x-1;i++){
		cnt+=a[x-1]-a[i];
	}
	while(cnt>m){
		l++;
		r++;
		if(r>n-1){
			return false;
		}
		cnt-=a[r-1]-a[l-1];
		cnt+=(a[r]-a[r-1])*(r-l);
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	scanf("%d%d",&n,&m);
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}	
	sort(a.begin(),a.end());
	long long lo=0,hi=n;
	while(lo<=hi){
		long long mid=lo+(hi-lo)/2;
		if(check(a,mid)){
			lo=mid+1;
			ans=max(ans,mid);
		}else{
			hi=mid-1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
