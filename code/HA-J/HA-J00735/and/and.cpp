#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],poww[33];
int v[33],e[200005][33];
int ans,n,m,o[200005];
void dfs(int oo,int p,int x){
	if(x==n+1){
		int nw=poww[31]-1;
		for(int i=1;i<=n;++i)
			if(o[i]==1)nw&=a[i];
		ans=max(ans,nw);
		return;
	}
	if(p==0){
		o[x]=0;
		dfs(oo-1,p,x+1);
	}
	else if(oo==p){
		o[x]=1;
		dfs(oo-1,p-1,x+1);
	}else{
		o[x]=1;
		dfs(oo-1,p-1,x+1);
		o[x]=0;
		dfs(oo-1,p,x+1);
	}
}
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int o,j;cin>>n>>m;
	poww[0]=1;
	for(int i=1;i<=31;++i)poww[i]=poww[i-1]*2;
	int maxx=-1,sum=poww[31]-1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		sum&=a[i];
	}
	if(n<=20){
		ans=0;
		dfs(n,m,1);
		return cout<<ans,0;
	}
	if(m==1)return cout<<maxx,0;
	if(m==n)return cout<<sum,0;
	if(n<=2000&&n==m){
		for(int i=1;i<=n;++i){
			for(j=1;j<=n;++j){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		return cout<<ans,0;
	}
	sort(a+1,a+n+1);
	j=0;
	int vis=1;
	for(int i=1;i<=n;++i){
		while(poww[j]<=a[i]){
			++j;
		}
		if(poww[j]-1!=a[i]){
			vis=0;break;
		}
	}
	if(vis==1)return cout<<a[n-m+1],0;
	ans=0;
	while(1){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;++i)if(a[i]<=0)n=i-1;
		if(n<m)break;
		for(int i=1;i<=n;++i){
			o=a[i];
			j=0;
			while(o){
				e[i][j]=o%2;
				if(o%2==1)++v[j];
				o/=2;
				++j;
			}
		}
		int st=0;
		for(int i=30;i>=0;--i){
			if(v[i]>=m){
				st=i;break;
			}
		}
		for(int i=1;i<=n;++i){
			a[i]-=poww[st];
		}
		ans+=poww[st];
		for(int i=1;i<=n;++i){
			for(j=0;j<=30;++j){
				e[i][j]=0;
			}
		}
		for(int i=1;i<=30;++i)v[i]=0;
	}
	cout<<ans;
	return 0;
}
