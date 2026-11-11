#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ma=-1,sa[N];
long long gesa(){
	//cout<<"y2\n";
	long long maxn=-1;
	for(long long i=1;i<=n;i++)sa[i]=1;
	for(long long i=1;i<n;i++){
		for(long long j=i+1;j<=n;j++){
			if(a[j]==a[i])sa[i]++,sa[j]++;
		}
	}
	for(long long i=1;i<=n;i++)maxn=max(maxn,sa[i]);
	//cout<<"y3\n";
	return maxn;
}
void dfs(long long xm){
	//cout<<"y1\n";
	if(xm>=1){
		for(long long j=1;j<=n;j++){
			a[j]+=1;
			dfs(xm-1);
			a[j]-=1;
		}
	}
	else{
		ma=max(ma,gesa());
		//cout<<"y4\n";
		return;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	//cout<<"y\n";
	dfs(m);
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<ma;
	return 0;
}
