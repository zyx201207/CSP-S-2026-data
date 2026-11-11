#include<bits/stdc++.h>
using namespace std;
long long n,d,cnt,mi,a[2000005];
bool check(int l,int r){
	for(int i=l+1;i<=r;i++){
		if(a[i]-a[i-1]>d)return 0;
	}
	return 1;
}
int pd(int l,int r){
	long long x=a[l],sum=1;
	for(int i=l;i<r;i++){
		if(a[i+1]-x>d){
			x=a[i];
//			cout<<x<<' ';
			sum++;
		}
	}
	return sum;
}
void dfs(int x,int y,int k){
	if(x==y){
		if(k==mi)cnt++;
		return;
	}
	if(k>=mi||cnt==3)return;
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]>d)return;
//		cout<<x<<' '<<i<<'\n';
		dfs(i,y,k+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,T;
	cin>>C>>T;
	if(C==11||C==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			long long k=a[2]-a[1];
//			cout<<k<<' ';
			k=d/k;
			if(k==0||k==1){
				cout<<0<<'\n';
				continue;
			}
			k+=k-1;
			k=n-k;
			if(k<0){
				cout<<0<<'\n';
				continue;
			}
			cout<<k<<'\n';
		}
		return 0;
	}
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				cnt=0;
				if(a[j]-a[i]<=d||!check(i,j))continue;
				mi=pd(i,j);
//				cout<<i<<' '<<j<<' '<<mi<<'\n';
				dfs(i,j,0);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
