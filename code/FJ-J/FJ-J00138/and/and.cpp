#include<bits/stdc++.h>
using namespace std;
int n,m,f[4];
bool A=true,B=true,F=true;
long long a[200009],ans,tmp,maxn,sum,minn=4e9;
bool check(long long x){
	long long xx=x;
	while(xx){
		if(xx%2==0&&xx!=1) return false;
		xx/=2;
	}
	return true;
}
void dfs(int x,int nown){
	if(x==m){
		ans=max(ans,tmp);
		return ;
	}
	if(nown==n+1) return ;
	for(int i=0;i<=1;i++){
		if(i==0){
			dfs(x,nown+1);
		}
		else{
			long long tmpp=tmp;
			if(x==0) tmp=a[nown];
			else tmp&=a[nown];
			dfs(x+1,nown+1);
			tmp=tmpp;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
		if(i==1) sum=a[i];
		else sum&=a[i];
		if(a[i]>4) F=false;
		if(!check(a[i])) A=false;
	}
	if(F){
		for(int i=1;i<=n;i++) f[a[i]]++;
		if(f[3]>=m) cout<<3;
		else if(f[3]+f[2]>=m) cout<<2;
		else if(f[3]+f[1]>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	if(A){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	dfs(0,1);
	cout<<ans;
	return 0;
}
