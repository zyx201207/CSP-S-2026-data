#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int sum1[N],sum2[N];
int mx;
void dfs(int now,int sum,int s){
	if(now==m+1){
		mx=max(mx,sum);
		return;
	}
	if(s>n) return;
	for(int i=s;i<=n;i++){
		if(now==1) dfs(now+1,a[i],i+1);
		else dfs(now+1,sum&a[i],i+1);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(n<=20){
		dfs(1,0,1);
		cout << mx;
	}else if(m==1){
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		cout << mx;
	}else if(m==n){
		mx=a[1];
		for(int i=2;i<=n;i++) mx=mx&a[i];
		cout << mx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout << mx;
	}else if(m==n-1){
		sum1[1]=a[1];
		for(int i=2;i<=n;i++) sum1[i]=sum1[i-1]&a[i];
		sum2[n]=a[n];
		for(int i=n-1;i>=1;i--) sum2[i]=sum2[i+1]&a[i];
		int mx=sum2[2];
		for(int i=2;i<=n;i++){
			if(i==n) mx=max(mx,sum1[i-1]);
			else mx=max(mx,sum1[i-1]&sum2[i+1]);
		} 
		cout << mx;
	}else{
		sort(a+1,a+n+1);
		cout << a[n-m+1];
	}
	return 0;
}
