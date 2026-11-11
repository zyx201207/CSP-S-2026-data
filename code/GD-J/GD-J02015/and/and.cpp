#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],sum,ans,mx;
bool cmp(long long a,long long b){
	return a>b;
}
void dfs(long long c,long long z,long long xi){
	if(c==m){
		mx=max(mx,z);
		return ;
	}else{
		for(int i=1;i<=n;i++){
			if(xi==i)
				continue;
			dfs(c+1,(a[i]&z),xi);
		}
	}
	return ;
}
bool B=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)
			B=0;
		if(i==1)
			sum=a[1];
		else
			sum=(sum&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(m==2&&n<=9000){
		long long mx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)
					continue;
				mx=max(mx,(a[i]&a[j])); 
			}
		}
		cout<<mx;
		return 0;
	}else if(m==1){
		cout<<a[1];
		return 0;
	}else if(m==n){
		cout<<sum;
		return 0;
	}else if(n<=20){
		long long mx=0;
		for(int i=1;i<=n;i++){
			dfs(0,a[i],i);
		}
		cout<<mx;
		return 0;
	}
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
} 
