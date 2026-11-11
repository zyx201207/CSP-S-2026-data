#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans,ssum,maxn;
void dfs(int x,int k,long long sum){
	if(x>n){
		if(k==m) ans=max(ans,sum);
		return ;
	}
	if(k==0){
		dfs(x+1,k,sum);
		dfs(x+1,k+1,a[x]);
	}
	dfs(x+1,k,sum);
	dfs(x+1,k+1,sum&a[x]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool op=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) op=0;
		maxn=max(maxn,a[i]);
	}
	if(op==1){
		cout<<n-m;
		return 0;
	}
	if(m==n){
		ssum=a[1];
		for(int i=2;i<=n;i++){
			ssum=ssum&a[i];
		}
		cout<<ssum;
		return 0;
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
    }
    if(n<=20){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	if(n<=2000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(maxn<=4){
		long long suma=0,sumb=0,sumc=0,sumd=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) suma++;
			if(a[i]==2) sumb++;
			if(a[i]==3) sumc++;
			if(a[i]==4) sumd++;
		}
		if(2*min(sumb,sumc)>=m){
			cout<<2;
			return 0;
		}
		m-=2*min(sumc,sumd);
		if(m<=0){
			cout<<1;
			return 0;
		}
		if(m-abs(sumc-sumd)<=0&&abs(sumc-sumd)%2==0){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	op=0;
	long long p=1;
	for(int i=1;i<=21;i++){
		p*=2;
		if(a[3]+1==p) op=1;
	}
	if(op==1){
		cout<<a[n-m+1];
		return 0;
	}
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--){
	    ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
