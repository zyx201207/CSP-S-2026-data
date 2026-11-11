#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;
long long ans=0;
long long maxn=0;
long long sum=0;
bool cmp(int a,int b){
	return a>b;
}
void dfs(int stp,long long num,int less){
	if(less==0){
		ans=max(ans,num);
		return;
	} 
	if(stp>n) return;
	dfs(stp+1,(num&a[stp]),less-1);
	dfs(stp+1,num,less);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int st=0;
	long long B=1;
	for(int i=1;i<=31;i++) B*=2;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(sum==0) sum=a[i];
		sum=(sum&a[i]);
		if(i==m) st=sum;
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(m==1) cout << maxn;
	else if(m==n) cout << sum;
	else if(n<=20){
		dfs(1,B-1,m);
		cout << ans;
	}
	else if(n<=2000&&m==2){
		long long mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long t=(a[i]&a[j]);
				mx=max(mx,t);
			}
		}
		cout << mx;
	}
	else if(m==n-1){
		long long mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,(sum^a[i]));
		}
		cout << mx;
		
	}
	else{
		cout << a[m];
	}
	return 0;
}
