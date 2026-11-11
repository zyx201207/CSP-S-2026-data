#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int ans=-1;
map<int,bool> mp;
void dfs(int start,int sum,int cnt){
//	cout<<start<<" "<<sum<<endl;
	if(cnt==m){
		ans=max(ans,sum);
		return;
	}
	if(start>n){
		return;
	}
	if(sum<=ans)return;
	dfs(start+1,sum,cnt);
	dfs(start+1,sum&a[start],cnt+1);
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool flag1=1,flag2=1;
	for(int i=1;i<=30;i++){
		mp[(1<<i)-1]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mp[a[i]]!=1)flag1=0;
		if(a[i]!=i-1)flag2=0;
	}
	if(flag1==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	else if(flag2==1){
		int res=a[n];
		for(int i=n;i>=n-m+1;i--){
			res&=a[i];		
		}
		cout<<res;
	}
	else{
		dfs(1,(1<<30)-1,0);
		cout<<ans; 
	}
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/ 
