#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],s[N],ans;
bool pd(int l,int r){
	int sum=s[r]-s[l-1]-(a[n]-a[r])*(r-l+1);
	return sum<=m;
}
void solve(int i){
	int l=0,r=i,mid;
	while(l+1!=r){
		mid=(l+r)>>1;
		if(pd(mid,i)){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	ans=max(ans,i-r+1);
}
signed main(){
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[n]-a[i];
	}/*
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=n;i++)
		cout<<s[i]<<" ";
	cout<<"\n";*/
	for(int i=1;i<=n;i++){
		solve(i);
	}
	cout<<ans;
	return 0;
}
