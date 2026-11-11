#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long a[200005];
long long n,m;
void dfs(int x,int c,long long sum){
	// cout<<x<<" "<<c<<" "<<sum<<endl;
	if(x>n){
		if(c==m)ans=max(ans,sum);
		return;
	}
	dfs(x+1,c,sum);
	if(c<m)
		dfs(x+1,c+1,sum&a[x]);
}
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long start=0;
	for(int i=1;i<=35;i++)start=start*2+1;
	cin>>n>>m;
	long long cnt=0,maxn=0,aaa=start;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if((a[i]+1)&a[i]==0){
			cnt++;
		}
		aaa&=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==m){
		cout<<aaa;
		return 0;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(cnt==n){
		sort(a+1,a+n,cmp);
		cout<<a[m];
		return 0;
	}
	dfs(1,0,start);
	cout<<ans;
	return 0;
}
