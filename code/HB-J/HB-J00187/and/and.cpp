#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,init,cnt[200005][35];
deque<long long> d;
/*
int pd(){
	clock_t now=clock();
	if((now-time)>=CLOCKS_PER_SEC){
		return 1;
	}
	return 0;
}
*/
long long dfs(int now,int cnt){
	if(now==m+1){
		long long res=init;
		for(int i=0;i<d.size();i++){
			res&=d[i];
		}
		return res;
	}
	long long res=0;
	for(int i=cnt;i<=n;i++){
		d.push_back(a[i]);
		res=max(res,dfs(now+1,i+1));
		d.pop_back();
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	clock_t time=clock();	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n-1;i++){
			a[n]&=a[i];
		}
		cout<<a[n];
		return 0;
	}/*
	if(m==n-1){
		for(int i=1;i<=n;i++){
			
		}
		return 0;
	}*/
	for(int i=0;i<=30;i++){
		init+=(1<<i);
	}
	cout<<dfs(1,1);
	return 0;
}
