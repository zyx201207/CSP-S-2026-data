#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[200010];
bool brr[200010];
long long ans=0;
void process(long long s,long long z){
	if(z>m){
		ans=max(ans,s);
		return;
	}
	for(int i=1;i<=n;i++){
		if(brr[i]==0){
			brr[i]=1;
			process(s&&arr[i],z+1);
			brr[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long b,maxn;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
		b=max(b,arr[i]);
		maxn=maxn&&arr[i];
	}
	if(m==1){
		cout<<b;
		return 0;
	}
	if(m==n){
		cout<<maxn;
		return 0;
	}
	long long minn=1;
	for(int i=1;i<=31;i++){
		minn=minn*2+1;
	}
	process(minn,0);
	cout<<ans;
	return 0;
}
