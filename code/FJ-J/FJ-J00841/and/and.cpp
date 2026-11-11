#include<bits/stdc++.h>
using namespace std;
long long a[200005];
bool v[200005];
int n,m;
int maxx=0;
void dfs(int as,int l){
	if(l==m){
		maxx=max(maxx,as);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		if(as==-1)dfs(a[i],l+1);
		else dfs(as&a[i],l+1);
		v[i]=0;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		long long maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
		return 0;
	}
	if(n<=20){
		dfs(-1,0);
		cout<<maxx;
		return 0;
	}//while(1)rp+=INF;
	if(a[n]<4){
		int c[10]={0,0,0,0};
		for(int i=1;i<=n;i++){
			c[a[i]]++;
		}
		if(m<=c[3])cout<<3;
		else if(m<=c[3]+c[2])cout<<2;
		else if(m<=c[3]+c[2]+c[1])cout<<1;
		else cout<<0;
		return 0;
	}
	if(m==n-1){
		long long maxn=a[2];
		for(int i=3;i<=n;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
		return 0;
	}
	cout<<a[n-m+1];
	return 0;
} 
