#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool v[200005];
int maxans=0;
void dfs(int d,int ans){
	if(ans==0) return;
	if(d>m){
		maxans=max(maxans,ans);
		return;
	}
	if(ans<=maxans) return;
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			dfs(d+1,ans&a[i]);
			v[i]=0;
		}
	}
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int sum;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum&=a[i];
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==i-1) cnt++;
	}
	if(cnt==n){
		cout<<n-m;
		return 0;
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=30;j++){
			if(a[i]==(1<<j)-1){
				cnt++;
			}
		}
	}
	if(cnt==n){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,(1<<30)-1);
	cout<<maxans;
	return 0;
}
