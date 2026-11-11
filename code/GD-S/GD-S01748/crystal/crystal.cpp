#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500007],m;
int ans;
pair<int,int> gans(int x){
	long long ans=0,cnt=m;
	int arr=0;
	int q;
	for(int i=1;i<=n;i++){
		if(a[i]>x) break;
		arr=i;
	}
	for(int i=arr;i>=1;i--){
		if(cnt-x+a[i]<0){
			q=1;
			cnt=-1;
			break;
		}
		cnt-=x-a[i];
		ans++;
	}
	if(cnt>0) q=0;
	if(cnt==0) q=2;
	return {ans,q};
}
void dfs(long long l,long long r){
	if(l>r) return ;
	long long mid=(l+r)/2;
	pair<int,bool> p=gans(mid);
	ans=max(ans,p.first);
	if(p.second==0) dfs(mid+1,r);
	else if(p.second==1){
		dfs(mid+1,r);
		dfs(l,mid-1);
	}
	else return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long l=a[1],r=a[n];
	dfs(a[1],a[n]);
	cout<<ans;
	return 0;
}
