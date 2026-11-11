#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010];
long long ans;
//5 3
//31 3 1 15 7
void dfs(int p,int c,long long sum) {
	if(c==m) {
		ans=max(ans,sum);
		//	cout<<sum<<endl;
		return ;
	}
	for(int i=p; i<=n; i++) {
		//	cout<<sum<<endl;
		int cnt=sum&a[i];
		if(p==1)
			dfs(i+1,c+1,a[i]);
		else dfs(i+1,c+1,cnt);

	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long ma=0;
	long long mi=LONG_MAX;
	bool f=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		//cout<<endl;
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
		if(a[i]!=i-1) f=1;
	}
	
//	cout<<1;
//	dfs(1,0,0);
	//cout<<ans;
	if(f==0) {
		int c=1;
		ans=a[n];
		for(int i=n-1; i>=1; i--) {
			if(c==m) break;
			c++;
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1) {
		cout<<ma;
		return 0;
	} 
		if(m==n) {
		ans=a[1];
		for(int i=2; i<=n; i++) {
			ans=ans&a[i];
			//	cout<<ans<<endl;
		}
		cout<<ans;
		return 0;
	} 
	
//	cout<<pow(2,20);
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(a[i]==ma) cnt++;
	}
	if(cnt>=m) {
		cout<<ma;
		return 0;
	}

	if(m==n-1) {
		ans=(mi==a[1])?a[2]:a[1];
		for(int i=1; i<=n; i++) {
			if(a[i]!=mi) {
				ans=ans&a[i];
			}
		}
		cout<<ans;
		return 0;
	} 
	if(m==2) {
	//	cout<<ma;
		long long mma=0;
		for(int i=1; i<=n; i++) {
			if(a[i]!=ma) mma=max(mma,a[i]);
		}
		ans=mma&ma;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
