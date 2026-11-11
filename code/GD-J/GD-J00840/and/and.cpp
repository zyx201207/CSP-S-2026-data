#include <bits/stdc++.h>
using namespace std;
bool f4=true,f2=true;
long long n,m;
long long a[200000+10];
long long r=0;
bool cmp(long long a,long long b){
	return a>b;
}
void dfs(long long pos,long long k,long long sum){
	if(pos>n){
		if(k==0){
			r=max(r,sum);
		}
		return;
	}
	if(n-pos+1<k)return;
	dfs(pos+1,k,sum);
	if(k!=0)dfs(pos+1,k-1,sum&a[pos]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>4)f4=false;
		if(!((a[i]+1)&a[i]))f2=false;
	}
	if(n<=20){
		dfs(1,m,-1);
		cout << r;
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout << ans;
		return 0;
	}
	if(m==1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout << ans;
		return 0;
	}
	if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(f2 || f4 || n>=40){
		sort(a+1,a+n+1,cmp);
		long long ans=0;
		for(int i=1;i<=m;i++){
			ans&=a[i];
		}
		cout << ans;
		return 0;
	}
	dfs(1,m,-1);
	cout << r;
	return 0;
}
