#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[200010];
void dfs(long long i,long long cnt,long long he){
	if(cnt==m){
		ans=max(ans,he);
		return;
	}
	if(i==n){
		return;
	}
	dfs(i+1,cnt,he);
	dfs(i+1,cnt+1,he&a[i]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
	}else if(m==n){
		long long answer=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
		cout<<answer;
	}
	dfs(0,0,0x3f3f3f3f);
	cout<<ans;
	return 0;
}
