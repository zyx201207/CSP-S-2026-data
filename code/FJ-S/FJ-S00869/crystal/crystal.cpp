#include<iostream>
#include<algorithm>
#define int long long

using namespace std;

const int MAXN = 100000+7;

int n,m,a[MAXN],ans,d;
int diff[MAXN],ds[MAXN],sum;

inline int query(int begin, int end){
	int res=0,len=end-begin;
	for(int i=end;i>begin;--i){
		res+=diff[i]*len;
		--len;
	}
	return res;
}

int solve(){
	for(int i=n;i>0;--i)
	for(int j=1;j<=m;++j){
		if(i-j<1)break;
		if(query(i-j, i)>m)break;
		if(j+1>ans)ans=j+1;
	}
	
	return ans;
}

int solve2(){
	int sum=0;
	for(int i=1;i<m;++i){
		sum+=i*d;
		if(sum>m)break;
		++ans;
	}
	
	return ans;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n>5000){
		d=a[2]-a[1];
		cout<<solve2()+1;
		
		return 0;
	}
	sort(a, a+n);
	for(int i=1;i<=n;++i){
		sum+=(i-1)*(diff[i]=a[i]-a[i-1]);
		ds[i]=sum;
	}
	
	cout<<solve();
	
	return 0;
}
