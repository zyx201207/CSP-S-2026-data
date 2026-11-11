#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100008];
long long ans=INT_MIN;
long long o;
void dfs(int w,int cnt,int sum){
	cnt++;
	sum=sum&a[w];
	if(cnt==m){
		if(ans<sum) ans=sum;
		return;
	}
	for(int i=w+1;i<=n;i++){
		dfs(i,cnt,sum);
	}
}
int f1(long long n){
	for(int i=1;i<=21;i++){
		if(pow(2,i)-1==n){
			return 1;
		}
		else{
			return 0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f1(a[i])==1) o++;
	}
	if(o==n){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
		return 0;
	}
	for(int i=1;i<=n;i++){
		dfs(i,0,a[i]);
	}
	cout<<ans;
	return 0;
}
